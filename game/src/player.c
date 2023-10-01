#include "player.h"

struct player player_create(int x, int y, int d)
{
    return (struct player) { x, y, d };
}

int player_get_x(struct player * player)
{
    return player->x;
}
int player_get_y(struct player * player)
{
    return player->y;
}
int player_get_d(struct player * player)
{
    return player->d;
}

void player_set_x(struct player * player, int x)
{
    player->x = x;
}
void player_set_y(struct player * player, int y)
{
    player->y = y;
}
void player_set_d(struct player * player, int d)
{
    player->d = d;
}

void player_set_position(struct player * player, int x, int y)
{
    player->x = x;
    player->y = y;
}
