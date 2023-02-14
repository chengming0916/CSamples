#include "circle.h"
#include <math.h>
#include <stdio.h>

static uint32_t Circle_area_(Shape const *const me);
static void Circle_draw_(Shape const *const me);

void Circle_ctor(Circle *const me, int16_t x, int16_t y, uint16_t r)
{
    static struct ShapeVtbl const vtbl = {
        &Circle_area_,
        &Circle_draw_,
    };

    Shape_ctor(&me->super, x, y);
    me->super.vprt = &vtbl;
    me->r = r;
}

static uint32_t Circle_area_(Shape const *const me)
{
    Circle const *const me_ = (Circle const *)me;
    return pow(me_->r, 2) * 3.14;
}

static void Circle_draw_(Shape const *const me)
{
    Circle const *const me_ = (Circle const *)me;
    printf("Rectangle_draw_(x=%d,y=%d,r=%d)\n", Shape_getX(me), Shape_getY(me), me_->r);
}