#pragma once

#include "inputmanager.h"

class QGraphicsView;

class KeyboardManager : public InputManager
{
public:
    explicit KeyboardManager(QObject *parent);

protected:
    bool eventFilter(QObject *object, QEvent *event) Q_DECL_OVERRIDE;
};
