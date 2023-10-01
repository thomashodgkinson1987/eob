#ifndef MAP_H
#define MAP_H

struct map
{
    int width;
    int height;
    int length;
    int * data;
};

struct map map_create(int width, int height);
void map_free(struct map * map);

int map_get_width(struct map * map);
int map_get_height(struct map * map);
int map_get_length(struct map * map);
int * map_get_data(struct map * map);

void map_fill(struct map * map, int value);
int map_get(struct map * map, int x, int y);
void map_set(struct map * map, int x, int y, int value);

#endif
