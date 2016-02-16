#pragma once

#ifndef safeDelete
#define safeDelete(x)   \
if (x)                  \
{                       \
    delete x;           \
    x = nullptr;        \
}
#endif

#ifndef qSafeDelete
#define qSafeDelete(x)  \
if (x)                  \
{                       \
    x->deleteLater();   \
    x = nullptr;        \
}
#endif
