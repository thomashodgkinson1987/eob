#ifndef POINT_H
#define POINT_H

struct point
{
    int x;
    int y;
};

struct point point_create(int x, int y);

int point_get_x(struct point * point);
int point_get_y(struct point * point);

void point_set_x(struct point * point, int x);
void point_set_y(struct point * point, int y);

#endif
