#ifndef EVENTFILTER_H
#define EVENTFILTER_H
#include <qobject>
#include "application.h"
#include <QKeyEvent>

const Qt::KeyboardModifiers HOTKEY = Qt::ShiftModifier | Qt::ControlModifier;

class EventFilter:public QObject
{
    Q_OBJECT
public:
    EventFilter(QObject* parent);
    bool eventFilter(QObject* object, QEvent* event);

private:
    bool hotkey;
};

#endif // EVENTFILTER_H
