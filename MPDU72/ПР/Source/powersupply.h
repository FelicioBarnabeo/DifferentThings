#ifndef POWERSUPPLY_H
#define POWERSUPPLY_H

#include <QObject>
#include "QFile"
#include "QTimer"
#include <QDebug>
#include <QVector>
#include <QProcess>

struct battery_capacity{
    int voltage;
    int percent;
};

static QVector<battery_capacity> chargingTable = {
    {4050,	99},
    {4040,	98},
    {4020,	97},
    {4010,	96},
    {3990,	95},
    {3980,	94},
    {3970,	93},
    {3960,	92},
    {3950,	91},
    {3940,	90},
    {3930,	85},
    {3920,	81},
    {3910,	77},
    {3900,	73},
    {3890,	70},
    {3860,	65},
    {3830,	60},
    {3780,	55},
    {3760,	50},
    {3740,	45},
    {3720,	40},
    {3700,	35},
    {3680,	30},
    {3660,	25},
    {3640,	20},
    {3620,	17},
    {3600,	14},
    {3580,	13},
    {3560,	12},
    {3540,	11},
    {3520,	10},
    {3500,	9},
    {3480,	8},
    {3460,	7},
    {3440,	6},
    {3430,	5},
    {3420,	4},
    {3020,	0},
};

static QVector<battery_capacity> dischargingTable = {
    {4050, 100},
    {4035,	99},
    {4020,	98},
    {4010,	97},
    {4000,	96},
    {3990,	96},
    {3980,	95},
    {3970,	92},
    {3960,	91},
    {3950,	90},
    {3940,	88},
    {3930,	86},
    {3920,	84},
    {3910,	82},
    {3900,	80},
    {3890,	74},
    {3860,	69},
    {3830,	64},
    {3780,	59},
    {3760,	54},
    {3740,	49},
    {3720,	44},
    {3700,	39},
    {3680,	34},
    {3660,	29},
    {3640,	24},
    {3620,	19},
    {3600,	14},
    {3580,	13},
    {3560,	12},
    {3540,	11},
    {3520,	10},
    {3500,	9},
    {3480,	8},
    {3460,	7},
    {3440,	6},
    {3430,	5},
    {3420,	4},
    {3020,	0},
};

class PowerSupplySingleton : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float currentVolt READ currentVolt WRITE setCurrentVolt NOTIFY currentVoltChanged)
    Q_PROPERTY(bool charging READ charging WRITE setCharging NOTIFY chargingChanged)
    Q_PROPERTY(bool isSuspend READ isSuspend WRITE setIsSuspend NOTIFY isSuspendChanged)
    Q_PROPERTY(int suspendTime READ suspendTime WRITE setSuspendTime NOTIFY suspendTimeChanged)
    Q_PROPERTY(bool lowCharge READ lowCharge WRITE setLowCharge NOTIFY lowChargeChanged)
private:
    QFile m_batterystatus;
    QTimer *m_idleTimer = nullptr;
    static PowerSupplySingleton * m_instance ;
    float m_currentVolt = 0 ;
    bool m_isSuspend = false;
    bool m_lowCharge = false;
    bool m_charging = false;
    int m_suspendTime = 20000;

protected:
    PowerSupplySingleton(QObject *parent = 0);
public:
    static PowerSupplySingleton* Instance();
    ~PowerSupplySingleton();

    int getFdBattery() const
    {
        return m_batterystatus.handle();
    }

    float currentVolt() const
    {
        return m_currentVolt;
    }

    bool charging() const
    {
        return m_charging;
    }

    bool isSuspend()
    {
        return m_isSuspend;
    }

    int suspendTime()
    {
        return m_suspendTime;
    }

    void reloadIdleTimer(){
        m_idleTimer->start(m_suspendTime);
    }

    bool lowCharge() const
    {
        return m_lowCharge;
    }

signals:

    void currentVoltChanged(int currentVolt);

    void chargingChanged( bool charging);
    void isSuspendChanged(bool suspend);
    void suspendTimeChanged(int suspendTime);
    void sigSuspendSystem();
    void wakeUpSystem();
    void lowChargeChanged(bool lowCharge);

public slots:
    int getChargingPercent(int mkVoltage);
    void checkBatteryStatus();
    void setCurrentVolt(float currentVolt)
    {
        //qDebug()<<"set cur vt = "<<currentVolt;
        if (m_currentVolt == currentVolt)
            return;
        m_currentVolt = currentVolt;
        emit currentVoltChanged(currentVolt);
    }

    void setCharging(bool charging)
    {
        if (m_charging == charging)
            return;
        //qDebug()<<"setCharging "<< charging ;
        m_charging = charging;
        emit chargingChanged(charging);
    }


    void suspendSystem()
    {
        setIsSuspend(true);
        QFile fpwrstate("/sys/power/state");
        if(!fpwrstate.open(QIODevice::Truncate | QIODevice::WriteOnly)){
            //qDebug()<<"cant open file /sys/power/state";
            return;
        }
        fpwrstate.write("mem",qstrlen("mem"));
        fpwrstate.close();
    }

    void setIsSuspend(bool suspend)
    {
        m_isSuspend = suspend;
        if(!suspend)
        {
            QProcess cpuFreqReinit;
            cpuFreqReinit.start("/home/root/powersave.sh");
            cpuFreqReinit.waitForFinished(100);
            emit wakeUpSystem();
        }
        emit isSuspendChanged(suspend);
    }

    void setSuspendTime(int suspendTime)
    {
        m_suspendTime = suspendTime;
        //emit suspendTimeChanged(suspendTime);
    }

    void setLowCharge(bool lowCharge)
    {
        if (m_lowCharge == lowCharge)
            return;

        m_lowCharge = lowCharge;
        emit lowChargeChanged(lowCharge);
    }
};

#endif // POWERSUPPLY_H
