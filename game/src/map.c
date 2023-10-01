#include "map.h"

#include <assert.h>
#include <stdlib.h>

struct map map_create(int width, int height)
{
    assert(width > 0);
    assert(height > 0);

    struct map map = (struct map){ 0 };

    map.width = width;
    map.height = height;
    map.length = map.width * map.height;
    map.data = calloc(map.length, sizeof(int));
    assert(map.data != NULL);

    return map;
}

void map_free(struct map * map)
{
    map->width = 0;
    map->height = 0;
    map->length = 0;
    free(map->data);
    map->data = NULL;
}

int map_get_width(struct map * map)
{
    return map->width;
}
int map_get_height(struct map * map)
{
    return map->height;
}
int map_get_length(struct map * map)
{
    return map->length;
}
int * map_get_data(struct map * map)
{
    return map->data;
}

void map_fill(struct map * map, int value)
{
    for (int i = 0; i < map->length; ++i)
    {
        map->data[i] = value;
    }
}

int map_get(struct map * map, int x, int y)
{
    assert(x >= 0 && x < map->width);
    assert(y >= 0 && y < map->height);

    return map->data[y * map->width + x];
}

void map_set(struct map * map, int x, int y, int value)
{
    assert(x >= 0 && x < map->width);
    assert(y >= 0 && y < map->height);

    map->data[y * map->width + x] = value;
}
