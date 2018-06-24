#include "lift_door.h"


CDoor::CDoor()
{
    state = CLOSE;
    QObject::connect(this, SIGNAL(OpenDoor()), this, SLOT(slotOpening()));
    QObject::connect(&timerOpen,    SIGNAL(timeout()), this, SLOT(slotOpen()));
    QObject::connect(&timerClose,   SIGNAL(timeout()), this, SLOT(slotClose()));
    QObject::connect(&timerWaitOpen,SIGNAL(timeout()), this, SLOT(slotClosing()));
}

void CDoor::slotOpen()
{
    if(state == OPENING) {
        state = OPEN;
        qDebug() << "Двери открылись";
        timerWaitOpen.start(TIME_DOOR_WAIT);
    }
}

void CDoor::slotClose()
{
    if(state == CLOSING) {
        state = CLOSE;
        qDebug() << "Двери закрылись";
        emit DoorIsClosed();
    }
}

void CDoor::slotOpening()
{
    if(state == CLOSE) {
        state = OPENING;
        qDebug() << "Двери открываются";
        timerOpen.start(TIME_DOOR);
    }
    if(state == CLOSING) {
        state = OPENING;
        qDebug() << "Двери открываются";
        int t = timerClose.remainingTime();
        timerClose.stop();
        timerOpen.start(TIME_DOOR - t);
    }
}

void CDoor::slotClosing()
{
    if(state == OPEN) {
        state = CLOSING;
        qDebug() << "Двери закрываются";
        timerClose.start(TIME_DOOR);
    }
}
