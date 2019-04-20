#ifndef OPTION_H
#define OPTION_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class Option : public QWidget
{
    Q_OBJECT
    QLineEdit *m_airshowIp, *m_airshowPort;
    QLineEdit *m_infoIp, *m_infoPort;
    QLabel *m_airshowIpLbl, *m_airshowPortLbl;
    QLabel *m_infoIpLbl, *m_infoPortLbl, *m_verLbl;
    QPushButton *m_applyBtn;
public:
    explicit Option(QWidget *parent = 0);

signals:
    void airshowServerConfigChanged(QString,QString);
    void infoServerConfigChanged(QString,QString);

public slots:
    void apply(void);
};

#endif // OPTION_H
