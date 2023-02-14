#include <stdio.h>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"

int main()
{
    Shape s1, s2;
    Rectangle r1, r2;
    Circle c1, c2;

    const Shape *shapes[] = {
        &c1.super,
        &c2.super,
        &r1.super,
        &r2.super,
    };

    Shape const *s;

    Shape_ctor(&s1, 0, 1);
    Shape_ctor(&s2, -1, 2);

    printf("Shape s1(x=%d,y=%d)\n", Shape_getX(&s1), Shape_getY(&s1));
    printf("Shape s1(x=%d,y=%d)\n", Shape_getX(&s2), Shape_getY(&s2));

    Shape_moveBy(&s1, 2, -4);
    Shape_moveBy(&s2, 1, -2);

    printf("Shape s1(x=%d,y=%d)\n", Shape_getX(&s1), Shape_getY(&s1));
    printf("Shape s2(x=%d,y=%d)\n", Shape_getX(&s2), Shape_getY(&s2));

    Rectangle_ctor(&r1, 0, 2, 10, 15);
    Rectangle_ctor(&r2, -1, 3, 5, 8);

    printf("Rect r1(x=%d,y=%d,width=%d,height=%d)\n", Shape_getX(&r1.super), Shape_getY(&r1.super), r1.width, r1.height);

    printf("Rect r2(x=%d,y=%d,width=%d,height=%d)\n", Shape_getX(&r2.super), Shape_getY(&r2.super), r2.width, r2.height);

    Shape_moveBy((Shape *)&r1, -2, 3);
    Shape_moveBy((Shape *)&r2, 2, -1);

    printf("Rect r1(x=%d,y=%d,width=%d,height=%d)\n", Shape_getX(&r1.super), Shape_getY(&r1.super), r1.width, r1.height);

    printf("Rect r2(x=%d,y=%d,width=%d,height=%d)\n", Shape_getX(&r2.super), Shape_getY(&r2.super), r2.width, r2.height);

    Circle_ctor(&c1, 1, -2, 12);
    Circle_ctor(&c2, 1, -3, 6);

    s = largestShape(shapes, sizeof(shapes) / sizeof(shapes[0]));
    printf("largetsShape s(x=%d,y=%d)\n", Shape_getX(s), Shape_getY(s));

    drawAllShapes(shapes, sizeof(shapes) / sizeof(shapes[0]));

    return 0;
}