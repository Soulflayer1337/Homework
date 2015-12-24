#pragma once

#ifndef safeDelete
#define safeDelete(x)   \
if (x)                  \
{                       \
    delete x;           \
    x = nullptr;        \
}
#endif
