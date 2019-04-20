#ifndef MYTABLEDELEGATE_H
#define MYTABLEDELEGATE_H

#include <QStyledItemDelegate>
#include <QString>
#include <QWidget>

class QValidator;
class MyValidator;

class MyTableDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit MyTableDelegate(QObject * parent = Q_NULLPTR);

    ~MyTableDelegate();
protected:
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget* editor, const QModelIndex & index) const override;
    void setModelData(QWidget * editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    //void sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
signals:

public slots:
    void clearDelegate();
    void setValidator(MyValidator *val);
    void setHexValidate();
    void setDecValidate();
    void setOctValidate();
    void setBinValidate();
    void setAsciiValidate();
private:
    MyValidator *m_validator = nullptr;
};

#endif // MYTABLEDELEGATE_H
