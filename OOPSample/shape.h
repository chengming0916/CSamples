#ifndef SHAPE_H
#define SHAPE_H

#include <stdint.h>

struct ShapeVtbl;

// Shape的属性
typedef struct
{
    struct ShapeVtbl const *vprt;

    int16_t x;
    int16_t y;
} Shape;

// Shape的虚表
struct ShapeVtbl
{
    uint32_t (*area)(Shape const *const me);
    void (*draw)(Shape const *const me);
};

void Shape_ctor(Shape *const me, int16_t x, int16_t y);
void Shape_moveBy(Shape *const me, int16_t x, int16_t y);

int16_t Shape_getX(Shape const *const me);
int16_t Shape_getY(Shape const *const me);

static uint32_t Shape_area(Shape const *const me)
{
    return (*me->vprt->area)(me);
}

static void Shape_draw(Shape const *const me)
{
    (*me->vprt->draw)(me);
}

Shape const *largestShape(Shape const *shapes[], uint32_t nShapes);
void drawAllShapes(Shape const *shapes[], uint32_t nShapes);

#endif /* SHAPE_H */