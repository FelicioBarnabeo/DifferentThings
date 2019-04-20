#include "consolewidget.h"
#include <QDebug>

Console::Console(QWidget *parent ) : QPlainTextEdit(parent)
{
    prompt = "Receiver1: ";
    QPalette p = palette();
    p.setColor(QPalette::Base,Qt::black);
    p.setColor(QPalette::Text,Qt::green);
    setPalette(p);

    history = new QStringList;
    historyPos = 0;
    insertPrompt(false);
    isLocked = false;
}

Console::~Console()
{

}

void Console::insertPrompt(bool insertNewBlock)
{
    QTextCharFormat format;
    format.setForeground(Qt::green);
    textCursor().setBlockCharFormat(format);

    if(insertNewBlock)
        textCursor().insertBlock();
    textCursor().insertText(prompt.append(" : "));
    scrollDown();
}

void Console::scrollDown()
{
    QScrollBar *vbar = verticalScrollBar();
    vbar->setValue(vbar->maximum());
}

void Console::mousePressEvent(QMouseEvent *e)
{
    setFocus();
}

void Console::keyPressEvent(QKeyEvent *e)
{
    if(isLocked)
        return;
    //При вводе обычных букв и цифр и с-в они добавляются в строку команды
//    if((e->key() >= 0x20 && e->key() <= 0x7e)
//        && (e->modifiers() == Qt::NoModifier || e->modifiers() == Qt::ShiftModifier))
//        QPlainTextEdit::keyPressEvent(e);
    //Реакция на клавишу backspace
//    if((e->key() == Qt::Key_Backspace)
//        && e->modifiers() == Qt::NoModifier
//            && textCursor().positionInBlock() >> prompt.length())
//        QPlainTextEdit::keyPressEvent(e);
    //Определяю реакцию виджета на ввод команды
//    if(e->key() == Qt::Key_Return && e->modifiers() == Qt::NoModifier)
//        onEnter();
    //Для сохранения истории команд
    if(e->key() == Qt::Key_Up && e->modifiers() == Qt::NoModifier)
        historyBack();
    if(e->key() == Qt::Key_Down && e->modifiers() == Qt::NoModifier)
        historyForward();
    //QString cmd = textCursor().block().text().mid(prompt.length());
    //emit onChange(cmd);
}

void Console::historyAdd(QString word)
{
    history->append(word);
    historyPos = history->length();
}

void Console::historyBack()
{
    if(!historyPos)
        return;
    QTextCursor cursor = textCursor();
    cursor.movePosition(QTextCursor::StartOfBlock);
    cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
    cursor.removeSelectedText();
    cursor.insertText(prompt + history->at(historyPos - 1));
    setTextCursor(cursor);
    historyPos--;
}

void Console::historyForward()
{
    if(historyPos == history->length())
        return;
    QTextCursor cursor = textCursor();
    cursor.movePosition(QTextCursor::StartOfBlock);
    cursor.movePosition(QTextCursor::EndOfBlock,QTextCursor::KeepAnchor);
    cursor.removeSelectedText();
    if(historyPos == history->length() - 1)
        cursor.insertText(prompt);
    else
        cursor.insertText(prompt + history->at(historyPos + 1));
    setTextCursor(cursor);
    historyPos++;
}

//void Console::onEnter()
//{
//    if(textCursor().positionInBlock() == prompt.length())
//    {
//        insertPrompt();
//        return;
//    }
//    QString cmd = textCursor().block().text().mid(prompt.length());
//    isLocked = true;
//    historyAdd(cmd);
//    emit onCommand(cmd);
//}

void Console::output(QString label, QString word)
{
    QTextCharFormat format;
    format.setForeground(Qt::white);
    textCursor().setBlockCharFormat(format);

    textCursor().insertBlock();   
    setPrompt(label);
    insertPrompt();
    textCursor().insertText(word);
    isLocked = false;
    printf("output: %s \n", word.toStdString().c_str());
}



