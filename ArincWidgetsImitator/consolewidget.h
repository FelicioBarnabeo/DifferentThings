#ifndef CONSOLEWIDGET_H
#define CONSOLEWIDGET_H

#include <QPlainTextEdit>
#include <QTextCursor>
#include <QScrollBar>
#include <QTextBlock>
#include <QObject>

class Console : public QPlainTextEdit
{
    Q_OBJECT
private:
    QString prompt;
    QStringList *history;
    int historyPos;
    bool isLocked;
    void insertPrompt(bool insertNewBlock = true);
public:
    Console(QWidget *parent = 0);
    ~Console();
    //void onEnter();
    void historyAdd(QString word);
    void historyBack();
    void historyForward();
    void scrollDown();
    void setPrompt(QString label)
    {
        prompt = label;
    }
protected:
    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *){};
    void contextMenuEvent(QContextMenuEvent *){};

public slots:
    void output(QString label,QString word);
signals:
    void onCommand(QString);
    void onChange(QString);
};

#endif // CONSOLEWIDGET_H
