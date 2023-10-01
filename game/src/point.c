#include "point.h"

struct point point_create(int x, int y)
{
    return (struct point) { x, y };
}

int point_get_x(struct point * point)
{
    return point->x;
}
int point_get_y(struct point * point)
{
    return point->y;
}

void point_set_x(struct point * point, int x)
{
    point->x = x;
}
void point_set_y(struct point * point, int y)
{
    point->y = y;
}
