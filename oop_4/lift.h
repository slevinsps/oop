#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include "times.h"
#include "lift_contr.h"
#include "lift_cab.h"

class CLift : public QObject
{
    Q_OBJECT
public:
    explicit CLift(QObject *parent = 0);

    QWidget* GetWidget();

signals:

public slots:

private:
    CController control;
    CCabin      cabina;
};

#endif // LIFT_H
