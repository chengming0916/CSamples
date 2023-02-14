#include <stdio.h>
#include "shape.h"
#include "rectangle.h"

// Rectangle虚函数
static uint32_t Rectangle_area_(Shape const *const me);
static void Rectangle_draw_(Shape const *const me);

// 构造函数
void Rectangle_ctor(Rectangle *const me, int16_t x, int16_t y, uint16_t width, uint16_t height)
{
    static struct ShapeVtbl const vtbl = {
        &Rectangle_area_,
        &Rectangle_draw_};

    Shape_ctor(&me->super, x, y);
    me->super.vprt = &vtbl;
    me->width = width;
    me->height = height;
}

// Rectangle的虚函数实现
static uint32_t Rectangle_area_(Shape const *const me)
{
    Rectangle const *const me_ = (Rectangle const *)me; // 显式转换
    return (uint32_t)me_->width * (uint32_t)me_->height;
}

static void Rectangle_draw_(Shape const *const me)
{
    Rectangle const *const me_ = (Rectangle const *)me;
    printf("Rectangle_draw_(x=%d,y=%d,width=%d,height=%d)\n",
     Shape_getX(me), Shape_getY(me), me_->width, me_->height);
}