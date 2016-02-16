#pragma once

#include "inputmanager.h"

class QGraphicsView;

/**
 * \brief The KeyboardManager class handles keyboard input.
 */
class KeyboardManager : public InputManager
{
public:
    explicit KeyboardManager(QObject *parent);

protected:
    bool eventFilter(QObject *object, QEvent *event) Q_DECL_OVERRIDE;
};
