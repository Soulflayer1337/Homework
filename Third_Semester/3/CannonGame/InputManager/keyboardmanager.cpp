#include "keyboardmanager.h"

#include <QKeyEvent>
#include <QGraphicsView>

KeyboardManager::KeyboardManager(QObject *parent) :
    InputManager(parent)
{
    parent->installEventFilter(this);
}

bool KeyboardManager::eventFilter(QObject *object, QEvent *event)
{
    if (object == parent())
    {
        if (event->type() == QEvent::KeyPress)
        {
            if (pressed_ != Qt::Key_unknown)
            {
                return false;
            }

            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

            if (keyEvent->key() == Qt::Key_Right)
            {
                pressed_ = Qt::Key_Right;
                emit moveRightPressed();
            }
            else if (keyEvent->key() == Qt::Key_Left)
            {
                pressed_ = Qt::Key_Left;
                emit moveLeftPressed();
            }
            else if (keyEvent->key() == Qt::Key_Up)
            {
                pressed_ = Qt::Key_Up;
                emit angleUpPressed();
            }
            else if (keyEvent->key() == Qt::Key_Down)
            {
                pressed_ = Qt::Key_Down;
                emit angleDownPressed();
            }
            else if (keyEvent->key() == Qt::Key_Enter)
            {
                pressed_ = Qt::Key_Enter;
                emit shootPressed();
            }
            else if (keyEvent->key() == Qt::Key_Q)
            {
                pressed_ = Qt::Key_Q;
                emit changePressed();
            }

            return true;
        }
        else if (event->type() == QEvent::KeyRelease)
        {
            if (pressed_ == static_cast<QKeyEvent *>(event)->key())
            {
                pressed_ = Qt::Key_unknown;
                emit buttonReleased();
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    QObject::eventFilter(object, event);
}

