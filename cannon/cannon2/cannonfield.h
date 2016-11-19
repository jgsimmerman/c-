 #ifndef CANNONFIELD_H
 #define CANNONFIELD_H

 #include <QWidget>

 class CannonField : public QWidget
 {
     Q_OBJECT

 public:
     CannonField(QWidget *parent = 0);

     int angle() const { return currentAngle; }
     int force() const { return currentForce; }

 public slots:
     void setAngle(int angle);
     void setForce(int force);

 signals:
     void angleChanged(int newAngle);
     void forceChanged(int newForce);

 protected:
     void paintEvent(QPaintEvent *event);

 private:
     QRect cannonRect() const;

     int currentAngle;
     int currentForce;
 };

 #endif
