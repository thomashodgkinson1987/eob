#ifndef PLAYER_H
#define PLAYER_H

struct player
{
    int x;
    int y;
    int d;
};

struct player player_create(int x, int y, int d);

int player_get_x(struct player * player);
int player_get_y(struct player * player);
int player_get_d(struct player * player);

void player_set_x(struct player * player, int x);
void player_set_y(struct player * player, int y);
void player_set_d(struct player * player, int d);

void player_set_position(struct player * player, int x, int y);

#endif
