#ifndef LIFTCAB_H
#define LIFTCAB_H

#include <QObject>
#include "lift_door.h"
#include "times.h"

class CCabin : public QObject
{
    Q_OBJECT
    enum StateCabin {
        MOVING,
        BUSY,
        FREE
    };

public:
    explicit CCabin(QObject *parent = 0);


signals:

    void FloorVisited(int floor, Direction d); // union?
    void FloorTargetAchieved(int floor, Direction d); // union?

public slots:

    void slotMoving();
    void slotFree();
    void slotBusy(int floor);

private:

    int       currentFloor = 0;
    int       targetFloor;
    Direction direct;
    StateCabin state;
    CDoor     door;
    QTimer    timerMoveFloor;

signals:

    void FloorAchieved();
    void Move();

};

#endif // LIFTCAB_H
