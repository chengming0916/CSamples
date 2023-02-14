#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

typedef struct
{
    Shape super;

    uint16_t r;
} Circle;

void Circle_ctor(Circle *const me, int16_t x, int16_t y, uint16_t r);

#endif /* CIRCLE_H */