#ifndef COLORDEFINER_H
#define COLORDEFINER_H

#include <QImage>
#include <QQuickItem>
#include <QString>
#include <QPoint>

class ColorDefiner: public QQuickItem {
    Q_OBJECT
    Q_DISABLE_COPY(ColorDefiner)
    Q_PROPERTY(int rad READ rad WRITE setRad NOTIFY radChanged)
    Q_PROPERTY(QPoint center READ center WRITE setCenter NOTIFY centerChanged)
    QImage m_image;
    int m_rad;
    QPoint m_center;
public:
    ColorDefiner(QQuickItem* parent =0);
    ~ColorDefiner(){}

    int rad() const
    {
        return m_rad;
    }

    QPoint center() const
    {
        return m_center;
    }

public slots:
    void loadImage(const QString img, const int scalex, const int scaley);
    QString getColor(int x,int y) const;
    QString getColorByRadians(double angle) const ;
    QString getColorByDegrees(int angle) const;
    int getAngleByCoordinates(int x, int y, int x0, int y0) const;
    int oddAngle(float angle) const;
    void makeColorWheelMap(int degreesStep=2, int lightStep=10) const;
    QString getColorValue(QString name,int procent) const;
    void setRad(int rad)
    {
        if (m_rad == rad)
            return;

        m_rad = rad;
        emit radChanged(m_rad);
    }
    void setCenter(QPoint center)
    {
        if (m_center == center)
            return;

        m_center = center;
        emit centerChanged(m_center);
    }

signals:
    void radChanged(int rad);
    void centerChanged(QPoint center);
};

#endif // COLORDEFINER_H
