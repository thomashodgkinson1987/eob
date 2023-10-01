#include "map.h"
#include "player.h"
#include "point.h"
#include "sprite.h"

#include "raylib.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



struct movement_delta
{
    Vector2 direction_delta;
    int rotation_delta;
};



Texture2D texture_y0_left_1;
Texture2D texture_y0_left_2;

Texture2D texture_y1_left_1;
Texture2D texture_y1_left_2;
Texture2D texture_y1_face_1;
Texture2D texture_y1_face_2;

Texture2D texture_y2_left_1;
Texture2D texture_y2_left_2;
Texture2D texture_y2_face_1;
Texture2D texture_y2_face_2;

Texture2D texture_y3_left_1;
Texture2D texture_y3_left_2;
Texture2D texture_y3_face_1;
Texture2D texture_y3_face_2;

Texture2D texture_top;
Texture2D texture_back;

size_t array_textures_count;
Texture2D * array_textures;

RenderTexture2D render_texture_main;
bool is_dirty_render_texture_main;

size_t array_sprites_count;
struct sprite * array_sprites;

//

struct sprite * sprite_top_1;
struct sprite * sprite_top_2;

struct sprite * sprite_back_1;
struct sprite * sprite_back_2;

//

struct sprite * sprite_y3_xm2_face_1;
struct sprite * sprite_y3_xm2_face_2;
struct sprite * sprite_y3_xm2_side_1;
struct sprite * sprite_y3_xm2_side_2;

struct sprite * sprite_y3_xm1_face_1;
struct sprite * sprite_y3_xm1_face_2;
struct sprite * sprite_y3_xm1_side_1;
struct sprite * sprite_y3_xm1_side_2;

struct sprite * sprite_y3_x2_face_1;
struct sprite * sprite_y3_x2_face_2;
struct sprite * sprite_y3_x2_side_1;
struct sprite * sprite_y3_x2_side_2;

struct sprite * sprite_y3_x1_face_1;
struct sprite * sprite_y3_x1_face_2;
struct sprite * sprite_y3_x1_side_1;
struct sprite * sprite_y3_x1_side_2;

struct sprite * sprite_y3_x0_face_1;
struct sprite * sprite_y3_x0_face_2;

//

struct sprite * sprite_y2_xm2_side_1;
struct sprite * sprite_y2_xm2_side_2;

struct sprite * sprite_y2_xm1_face_1;
struct sprite * sprite_y2_xm1_face_2;
struct sprite * sprite_y2_xm1_side_1;
struct sprite * sprite_y2_xm1_side_2;

struct sprite * sprite_y2_x2_side_1;
struct sprite * sprite_y2_x2_side_2;

struct sprite * sprite_y2_x1_face_1;
struct sprite * sprite_y2_x1_face_2;
struct sprite * sprite_y2_x1_side_1;
struct sprite * sprite_y2_x1_side_2;

struct sprite * sprite_y2_x0_face_1;
struct sprite * sprite_y2_x0_face_2;

//

struct sprite * sprite_y1_xm1_face_1;
struct sprite * sprite_y1_xm1_face_2;
struct sprite * sprite_y1_xm1_side_1;
struct sprite * sprite_y1_xm1_side_2;

struct sprite * sprite_y1_x1_face_1;
struct sprite * sprite_y1_x1_face_2;
struct sprite * sprite_y1_x1_side_1;
struct sprite * sprite_y1_x1_side_2;

struct sprite * sprite_y1_x0_face_1;
struct sprite * sprite_y1_x0_face_2;

//

struct sprite * sprite_y0_xm1_1;
struct sprite * sprite_y0_xm1_2;

struct sprite * sprite_y0_x1_1;
struct sprite * sprite_y0_x1_2;

//

struct map map;

struct point points[15];

struct player player;

//

Texture2D texture_play_field;
Texture2D texture_north;
Texture2D texture_south;
Texture2D texture_east;
Texture2D texture_west;

struct sprite sprite_play_field;
struct sprite sprite_north;
struct sprite sprite_east;
struct sprite sprite_south;
struct sprite sprite_west;



void game_init(void);
void game_free(void);
void game_update(void);
void game_draw(void);

struct movement_delta get_movement_delta(void);

void handle_player_input(struct movement_delta movement_delta);

void update_compass_sprites(void);
void toggle_background_and_top_sprites(void);
void update_visible_wall_sprites(void);



int main(void)
{
    InitWindow(1280, 800, "eob");
    SetTargetFPS(60);

    game_init();

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_R))
        {
            game_free();
            game_init();
        }

        game_update();
        game_draw();
    }

    game_free();

    CloseWindow();

    return 0;
}



void game_init(void)
{
    array_textures_count = 16;
    array_textures = calloc(array_textures_count, sizeof(Texture2D));
    assert(array_textures != NULL);

    texture_y0_left_1 = LoadTexture("resources/y0_left_1.png");
    texture_y0_left_2 = LoadTexture("resources/y0_left_2.png");

    texture_y1_left_1 = LoadTexture("resources/y1_left_1.png");
    texture_y1_left_2 = LoadTexture("resources/y1_left_2.png");
    texture_y1_face_1 = LoadTexture("resources/y1_face_1.png");
    texture_y1_face_2 = LoadTexture("resources/y1_face_2.png");

    texture_y2_left_1 = LoadTexture("resources/y2_left_1.png");
    texture_y2_left_2 = LoadTexture("resources/y2_left_2.png");
    texture_y2_face_1 = LoadTexture("resources/y2_face_1.png");
    texture_y2_face_2 = LoadTexture("resources/y2_face_2.png");

    texture_y3_left_1 = LoadTexture("resources/y3_left_1.png");
    texture_y3_left_2 = LoadTexture("resources/y3_left_2.png");
    texture_y3_face_1 = LoadTexture("resources/y3_face_1.png");
    texture_y3_face_2 = LoadTexture("resources/y3_face_2.png");

    texture_top = LoadTexture("resources/top.png");
    texture_back = LoadTexture("resources/back.png");

    array_textures[0] = texture_y0_left_1;
    array_textures[1] = texture_y0_left_2;

    array_textures[2] = texture_y1_left_1;
    array_textures[3] = texture_y1_left_2;
    array_textures[4] = texture_y1_face_1;
    array_textures[5] = texture_y1_face_2;

    array_textures[6] = texture_y2_left_1;
    array_textures[7] = texture_y2_left_2;
    array_textures[8] = texture_y2_face_1;
    array_textures[9] = texture_y2_face_2;

    array_textures[10] = texture_y3_left_1;
    array_textures[11] = texture_y3_left_2;
    array_textures[12] = texture_y3_face_1;
    array_textures[13] = texture_y3_face_2;

    array_textures[14] = texture_top;
    array_textures[15] = texture_back;

    render_texture_main = LoadRenderTexture(320, 200);
    is_dirty_render_texture_main = true;

    array_sprites_count = 50;
    array_sprites = calloc(array_sprites_count, sizeof(struct sprite));
    assert(array_sprites != NULL);

    //

    array_sprites[0] = sprite_create_2(texture_top, 0, 0, false);
    array_sprites[1] = sprite_create_2(texture_top, 0, 0, true);

    array_sprites[2] = sprite_create_2(texture_back, 0, 8, false);
    array_sprites[3] = sprite_create_2(texture_back, 0, 8, true);

    //

    array_sprites[4] = sprite_create_2(texture_y3_face_1, -32, 24, false);
    array_sprites[5] = sprite_create_2(texture_y3_face_2, -32, 24, false);

    array_sprites[6] = sprite_create_2(texture_y3_left_1, 16, 24, false);
    array_sprites[7] = sprite_create_2(texture_y3_left_2, 16, 24, false);

    array_sprites[8] = sprite_create_2(texture_y3_face_1, 16, 24, false);
    array_sprites[9] = sprite_create_2(texture_y3_face_2, 16, 24, false);

    array_sprites[10] = sprite_create_2(texture_y3_left_1, 64, 24, false);
    array_sprites[11] = sprite_create_2(texture_y3_left_2, 64, 24, false);

    array_sprites[12] = sprite_create_2(texture_y3_face_1, 160, 24, true);
    array_sprites[13] = sprite_create_2(texture_y3_face_2, 160, 24, true);

    array_sprites[14] = sprite_create_2(texture_y3_left_1, 152, 24, true);
    array_sprites[15] = sprite_create_2(texture_y3_left_2, 152, 24, true);

    array_sprites[16] = sprite_create_2(texture_y3_face_1, 112, 24, true);
    array_sprites[17] = sprite_create_2(texture_y3_face_2, 112, 24, true);

    array_sprites[18] = sprite_create_2(texture_y3_left_1, 104, 24, true);
    array_sprites[19] = sprite_create_2(texture_y3_left_2, 104, 24, true);

    array_sprites[20] = sprite_create_2(texture_y3_face_1, 64, 24, false);
    array_sprites[21] = sprite_create_2(texture_y3_face_2, 64, 24, false);

    //

    array_sprites[22] = sprite_create_2(texture_y2_left_1, 0, 16, false);
    array_sprites[23] = sprite_create_2(texture_y2_left_2, 0, 16, false);

    array_sprites[24] = sprite_create_2(texture_y2_face_1, -32, 16, false);
    array_sprites[25] = sprite_create_2(texture_y2_face_2, -32, 16, false);

    array_sprites[26] = sprite_create_2(texture_y2_left_1, 48, 16, false);
    array_sprites[27] = sprite_create_2(texture_y2_left_2, 48, 16, false);

    array_sprites[28] = sprite_create_2(texture_y2_left_1, 160, 16, true);
    array_sprites[29] = sprite_create_2(texture_y2_left_2, 160, 16, true);

    array_sprites[30] = sprite_create_2(texture_y2_face_1, 128, 16, true);
    array_sprites[31] = sprite_create_2(texture_y2_face_2, 128, 16, true);

    array_sprites[32] = sprite_create_2(texture_y2_left_1, 112, 16, true);
    array_sprites[33] = sprite_create_2(texture_y2_left_2, 112, 16, true);

    array_sprites[34] = sprite_create_2(texture_y2_face_1, 48, 16, false);
    array_sprites[35] = sprite_create_2(texture_y2_face_2, 48, 16, false);

    //

    array_sprites[36] = sprite_create_2(texture_y1_face_1, -104, 8, false);
    array_sprites[37] = sprite_create_2(texture_y1_face_2, -104, 8, false);

    array_sprites[38] = sprite_create_2(texture_y1_left_1, 24, 8, false);
    array_sprites[39] = sprite_create_2(texture_y1_left_2, 24, 8, false);

    array_sprites[40] = sprite_create_2(texture_y1_face_1, 152, 8, true);
    array_sprites[41] = sprite_create_2(texture_y1_face_2, 152, 8, true);

    array_sprites[42] = sprite_create_2(texture_y1_left_1, 128, 8, true);
    array_sprites[43] = sprite_create_2(texture_y1_left_2, 128, 8, true);

    array_sprites[44] = sprite_create_2(texture_y1_face_1, 24, 8, false);
    array_sprites[45] = sprite_create_2(texture_y1_face_2, 24, 8, false);

    //

    array_sprites[46] = sprite_create_2(texture_y0_left_1, 0, 0, false);
    array_sprites[47] = sprite_create_2(texture_y0_left_2, 0, 0, false);

    array_sprites[48] = sprite_create_2(texture_y0_left_1, 152, 0, true);
    array_sprites[49] = sprite_create_2(texture_y0_left_2, 152, 0, true);

    //



    //

    sprite_top_1 = &array_sprites[0];
    sprite_top_2 = &array_sprites[1];

    sprite_back_1 = &array_sprites[2];
    sprite_back_2 = &array_sprites[3];

    //

    sprite_y3_xm2_face_1 = &array_sprites[4];
    sprite_y3_xm2_face_2 = &array_sprites[5];

    sprite_y3_xm2_side_1 = &array_sprites[6];
    sprite_y3_xm2_side_2 = &array_sprites[7];

    sprite_y3_xm1_face_1 = &array_sprites[8];
    sprite_y3_xm1_face_2 = &array_sprites[9];

    sprite_y3_xm1_side_1 = &array_sprites[10];
    sprite_y3_xm1_side_2 = &array_sprites[11];

    sprite_y3_x2_face_1 = &array_sprites[12];
    sprite_y3_x2_face_2 = &array_sprites[13];

    sprite_y3_x2_side_1 = &array_sprites[14];
    sprite_y3_x2_side_2 = &array_sprites[15];

    sprite_y3_x1_face_1 = &array_sprites[16];
    sprite_y3_x1_face_2 = &array_sprites[17];

    sprite_y3_x1_side_1 = &array_sprites[18];
    sprite_y3_x1_side_2 = &array_sprites[19];

    sprite_y3_x0_face_1 = &array_sprites[20];
    sprite_y3_x0_face_2 = &array_sprites[21];

    //

    sprite_y2_xm2_side_1 = &array_sprites[22];
    sprite_y2_xm2_side_2 = &array_sprites[23];

    sprite_y2_xm1_face_1 = &array_sprites[24];
    sprite_y2_xm1_face_2 = &array_sprites[25];

    sprite_y2_xm1_side_1 = &array_sprites[26];
    sprite_y2_xm1_side_2 = &array_sprites[27];

    sprite_y2_x2_side_1 = &array_sprites[28];
    sprite_y2_x2_side_2 = &array_sprites[29];

    sprite_y2_x1_face_1 = &array_sprites[30];
    sprite_y2_x1_face_2 = &array_sprites[31];

    sprite_y2_x1_side_1 = &array_sprites[32];
    sprite_y2_x1_side_2 = &array_sprites[33];

    sprite_y2_x0_face_1 = &array_sprites[34];
    sprite_y2_x0_face_2 = &array_sprites[35];

    //

    sprite_y1_xm1_face_1 = &array_sprites[36];
    sprite_y1_xm1_face_2 = &array_sprites[37];

    sprite_y1_xm1_side_1 = &array_sprites[38];
    sprite_y1_xm1_side_2 = &array_sprites[39];

    sprite_y1_x1_face_1 = &array_sprites[40];
    sprite_y1_x1_face_2 = &array_sprites[41];

    sprite_y1_x1_side_1 = &array_sprites[42];
    sprite_y1_x1_side_2 = &array_sprites[43];

    sprite_y1_x0_face_1 = &array_sprites[44];
    sprite_y1_x0_face_2 = &array_sprites[45];

    //

    sprite_y0_xm1_1 = &array_sprites[46];
    sprite_y0_xm1_2 = &array_sprites[47];

    sprite_y0_x1_1 = &array_sprites[48];
    sprite_y0_x1_2 = &array_sprites[49];

    //



    //

    for (int i = 0; i < array_sprites_count; ++i)
    {
        sprite_set_is_draw(&array_sprites[i], false);
    }
    sprite_set_is_draw(&array_sprites[1], true);
    sprite_set_is_draw(&array_sprites[2], true);

    map = map_create(32, 32);
    map_fill(&map, 0);

    int counter = 0;

    for (int i = 0; i < map_get_height(&map); ++i)
    {
        for (int j = 0; j < map_get_width(&map); ++j)
        {
            if (i == 0 || i == map_get_height(&map) - 1 || j == 0 || j == map_get_width(&map) - 1 || GetRandomValue(0, 100) > 80)
            {
                map_set(&map, j, i, counter % 2 == 0 ? 1 : 2);
                ++counter;
            }
        }
        ++counter;
    }

    points[0] = point_create(-1, 0);
    points[1] = point_create(1, 0);

    points[2] = point_create(-1, 1);
    points[3] = point_create(0, 1);
    points[4] = point_create(1, 1);

    points[5] = point_create(-2, 2);
    points[6] = point_create(-1, 2);
    points[7] = point_create(0, 2);
    points[8] = point_create(1, 2);
    points[9] = point_create(2, 2);

    points[10] = point_create(-2, 3);
    points[11] = point_create(-1, 3);
    points[12] = point_create(0, 3);
    points[13] = point_create(1, 3);
    points[14] = point_create(2, 3);

    player = player_create(3, 6, 0);

    texture_play_field = LoadTexture("resources/play_field.png");
    texture_north = LoadTexture("resources/north.png");
    texture_east = LoadTexture("resources/east.png");
    texture_south = LoadTexture("resources/south.png");
    texture_west = LoadTexture("resources/west.png");

    sprite_play_field = sprite_create_2(texture_play_field, 0, 0, false);
    sprite_north = sprite_create_2(texture_north, 112, 127, false);
    sprite_east = sprite_create_2(texture_east, 112, 127, false);
    sprite_south = sprite_create_2(texture_south, 112, 127, false);
    sprite_west = sprite_create_2(texture_west, 112, 127, false);

    update_compass_sprites();
    update_visible_wall_sprites();
}

void game_free(void)
{
    free(array_sprites);

    for (int i = 0; i < array_textures_count; ++i)
    {
        UnloadTexture(array_textures[i]);
    }

    free(array_textures);

    UnloadRenderTexture(render_texture_main);

    map_free(&map);

    UnloadTexture(texture_play_field);
    UnloadTexture(texture_north);
    UnloadTexture(texture_east);
    UnloadTexture(texture_south);
    UnloadTexture(texture_west);
}

void game_update(void)
{
    struct movement_delta movement_delta = get_movement_delta();

    int original_player_x = player_get_x(&player);
    int original_player_y = player_get_y(&player);
    int original_player_d = player_get_d(&player);

    handle_player_input(movement_delta);

    if (player_get_d(&player) != original_player_d)
    {
        update_compass_sprites();
        toggle_background_and_top_sprites();
        update_visible_wall_sprites();
    }
    else if (player_get_x(&player) != original_player_x || player_get_y(&player) != original_player_y)
    {
        toggle_background_and_top_sprites();
        update_visible_wall_sprites();
    }
}

void game_draw(void)
{
    if (is_dirty_render_texture_main)
    {
        BeginTextureMode(render_texture_main);

        ClearBackground(MAGENTA);

        for (int i = 0; i < array_sprites_count; ++i)
        {
            sprite_draw(&array_sprites[i]);
        }

        sprite_draw(&sprite_play_field);
        sprite_draw(&sprite_north);
        sprite_draw(&sprite_east);
        sprite_draw(&sprite_south);
        sprite_draw(&sprite_west);

        EndTextureMode();

        is_dirty_render_texture_main = false;
    }

    BeginDrawing();

    ClearBackground(GREEN);

    {
        Rectangle source = (Rectangle){ 0, 0, (float)render_texture_main.texture.width, -(float)render_texture_main.texture.height };
        Rectangle dest = (Rectangle){ 0, 0, (float)render_texture_main.texture.width * 4, (float)render_texture_main.texture.height * 4 };
        Vector2 origin = (Vector2){ 0, 0 };
        DrawTexturePro(render_texture_main.texture, source, dest, origin, 0, WHITE);
    }

    DrawText(TextFormat("x=%i y=%i d=%i", player_get_x(&player), player_get_y(&player), player_get_d(&player)), 8, 8, 8, SKYBLUE);
    DrawText(TextFormat("mouse x=%i y=%i", (int)GetMousePosition().x, (int)GetMousePosition().y), 8, 16, 8, SKYBLUE);

    EndDrawing();
}



struct movement_delta get_movement_delta(void)
{
    Vector2 direction_delta = (Vector2){ 0 };
    int rotation_delta = 0;

    if (IsKeyPressed(KEY_KP_4) || IsKeyPressed(KEY_A))
    {
        direction_delta.x = -1;
    }
    if (IsKeyPressed(KEY_KP_6) || IsKeyPressed(KEY_D))
    {
        direction_delta.x = 1;
    }
    if (IsKeyPressed(KEY_KP_8) || IsKeyPressed(KEY_W))
    {
        direction_delta.y = -1;
    }
    if (IsKeyPressed(KEY_KP_2) || IsKeyPressed(KEY_S))
    {
        direction_delta.y = 1;
    }

    if (IsKeyPressed(KEY_KP_7) || IsKeyPressed(KEY_Q))
    {
        rotation_delta = -1;
    }
    if (IsKeyPressed(KEY_KP_9) || IsKeyPressed(KEY_E))
    {
        rotation_delta = 1;
    }

    struct movement_delta movement_delta = (struct movement_delta){ 0 };
    movement_delta.direction_delta = direction_delta;
    movement_delta.rotation_delta = rotation_delta;

    return movement_delta;
}



void handle_player_input(struct movement_delta movement_delta)
{
    int new_player_x = player_get_x(&player);
    int new_player_y = player_get_y(&player);

    if (movement_delta.rotation_delta == -1)
    {
        player_set_d(&player, player_get_d(&player) - 1 < 0 ? 3 : player_get_d(&player) - 1);
    }
    else if (movement_delta.rotation_delta == 1)
    {
        player_set_d(&player, player_get_d(&player) + 1 > 3 ? 0 : player_get_d(&player) + 1);
    }

    if (movement_delta.direction_delta.y == -1)
    {
        if (player_get_d(&player) == 0)
            --new_player_y;
        else if (player_get_d(&player) == 1)
            ++new_player_x;
        else if (player_get_d(&player) == 2)
            ++new_player_y;
        else if (player_get_d(&player) == 3)
            --new_player_x;
    }
    if (movement_delta.direction_delta.y == 1)
    {
        if (player_get_d(&player) == 0)
            ++new_player_y;
        else if (player_get_d(&player) == 1)
            --new_player_x;
        else if (player_get_d(&player) == 2)
            --new_player_y;
        else if (player_get_d(&player) == 3)
            ++new_player_x;
    }
    if (movement_delta.direction_delta.x == -1)
    {
        if (player_get_d(&player) == 0)
            --new_player_x;
        else if (player_get_d(&player) == 1)
            --new_player_y;
        else if (player_get_d(&player) == 2)
            ++new_player_x;
        else if (player_get_d(&player) == 3)
            ++new_player_y;
    }
    if (movement_delta.direction_delta.x == 1)
    {
        if (player_get_d(&player) == 0)
            ++new_player_x;
        else if (player_get_d(&player) == 1)
            ++new_player_y;
        else if (player_get_d(&player) == 2)
            --new_player_x;
        else if (player_get_d(&player) == 3)
            --new_player_y;
    }

    if (
        (new_player_x != player_get_x(&player) || new_player_y != player_get_y(&player))
        && new_player_x >= 0
        && new_player_x < map_get_width(&map)
        && new_player_y >= 0
        && new_player_y < map_get_height(&map)
        )
    {
        if (map_get(&map, new_player_x, new_player_y) == 0)
        {
            player_set_x(&player, new_player_x);
            player_set_y(&player, new_player_y);
        }
    }
}



void update_compass_sprites(void)
{
    sprite_set_is_draw(&sprite_north, player_get_d(&player) == 0);
    sprite_set_is_draw(&sprite_east, player_get_d(&player) == 1);
    sprite_set_is_draw(&sprite_south, player_get_d(&player) == 2);
    sprite_set_is_draw(&sprite_west, player_get_d(&player) == 3);

    is_dirty_render_texture_main = true;
}

void toggle_background_and_top_sprites(void)
{
    sprite_toggle_is_draw(&array_sprites[0]);
    sprite_toggle_is_draw(&array_sprites[1]);
    sprite_toggle_is_draw(&array_sprites[2]);
    sprite_toggle_is_draw(&array_sprites[3]);

    is_dirty_render_texture_main = true;
}

void update_visible_wall_sprites(void)
{
    for (int i = 0; i < 15; ++i)
    {
        struct point * point = &points[i];

        int x = 0;
        int y = 0;

        if (player_get_d(&player) == 0)
        {
            x = player_get_x(&player) + point_get_x(point);
            y = player_get_y(&player) - point_get_y(point);
        }
        else if (player_get_d(&player) == 1)
        {
            x = player_get_x(&player) + point_get_y(point);
            y = player_get_y(&player) + point_get_x(point);
        }
        else if (player_get_d(&player) == 2)
        {
            x = player_get_x(&player) - point_get_x(point);
            y = player_get_y(&player) + point_get_y(point);
        }
        else if (player_get_d(&player) == 3)
        {
            x = player_get_x(&player) - point_get_y(point);
            y = player_get_y(&player) - point_get_x(point);
        }

        if (x >= 0 && x < map_get_width(&map) && y >= 0 && y < map_get_height(&map))
        {
            int value = map_get(&map, x, y);
            if (i == 0)
            {
                sprite_set_is_draw(sprite_y0_xm1_1, false);
                sprite_set_is_draw(sprite_y0_xm1_2, false);
                if (value == 1)
                    sprite_set_is_draw(sprite_y0_xm1_1, true);
                else if (value == 2)
                    sprite_set_is_draw(sprite_y0_xm1_2, true);
            }
            else if (i == 1)
            {
                sprite_set_is_draw(sprite_y0_x1_1, false);
                sprite_set_is_draw(sprite_y0_x1_2, false);
                if (value == 1)
                    sprite_set_is_draw(sprite_y0_x1_1, true);
                else if (value == 2)
                    sprite_set_is_draw(sprite_y0_x1_2, true);
            }
            else if (i == 2)
            {
                sprite_set_is_draw(sprite_y1_xm1_face_1, false);
                sprite_set_is_draw(sprite_y1_xm1_side_1, false);
                sprite_set_is_draw(sprite_y1_xm1_face_2, false);
                sprite_set_is_draw(sprite_y1_xm1_side_2, false);
                if (value == 1)
                {
                    sprite_set_is_draw(sprite_y1_xm1_face_1, true);
                    sprite_set_is_draw(sprite_y1_xm1_side_1, true);
                }
                else if (value == 2)
                {
                    sprite_set_is_draw(sprite_y1_xm1_face_2, true);
                    sprite_set_is_draw(sprite_y1_xm1_side_2, true);
                }
            }
            else if (i == 3)
            {
                sprite_set_is_draw(sprite_y1_x0_face_1, false);
                sprite_set_is_draw(sprite_y1_x0_face_2, false);
                if (value == 1)
                    sprite_set_is_draw(sprite_y1_x0_face_1, true);
                else if (value == 2)
                    sprite_set_is_draw(sprite_y1_x0_face_2, true);
            }
            else if (i == 4)
            {
                sprite_set_is_draw(sprite_y1_x1_face_1, false);
                sprite_set_is_draw(sprite_y1_x1_side_1, false);
                sprite_set_is_draw(sprite_y1_x1_face_2, false);
                sprite_set_is_draw(sprite_y1_x1_side_2, false);
                if (value == 1)
                {
                    sprite_set_is_draw(sprite_y1_x1_face_1, true);
                    sprite_set_is_draw(sprite_y1_x1_side_1, true);
                }
                else if (value == 2)
                {
                    sprite_set_is_draw(sprite_y1_x1_face_2, true);
                    sprite_set_is_draw(sprite_y1_x1_side_2, true);
                }
            }
            else if (i == 5)
            {
                sprite_set_is_draw(sprite_y2_xm2_side_1, false);
                sprite_set_is_draw(sprite_y2_xm2_side_2, false);
                if (value == 1)
                    sprite_set_is_draw(sprite_y2_xm2_side_1, true);
                else if (value == 2)
                    sprite_set_is_draw(sprite_y2_xm2_side_2, true);
            }
            else if (i == 6)
            {
                sprite_set_is_draw(sprite_y2_xm1_face_1, false);
                sprite_set_is_draw(sprite_y2_xm1_side_1, false);
                sprite_set_is_draw(sprite_y2_xm1_face_2, false);
                sprite_set_is_draw(sprite_y2_xm1_side_2, false);
                if (value == 1)
                {
                    sprite_set_is_draw(sprite_y2_xm1_face_1, true);
                    sprite_set_is_draw(sprite_y2_xm1_side_1, true);
                }
                else if (value == 2)
                {
                    sprite_set_is_draw(sprite_y2_xm1_face_2, true);
                    sprite_set_is_draw(sprite_y2_xm1_side_2, true);
                }
            }
            else if (i == 7)
            {
                sprite_set_is_draw(sprite_y2_x0_face_1, false);
                sprite_set_is_draw(sprite_y2_x0_face_2, false);
                if (value == 1)
                    sprite_set_is_draw(sprite_y2_x0_face_1, true);
                else if (value == 2)
                    sprite_set_is_draw(sprite_y2_x0_face_2, true);
            }
            else if (i == 8)
            {
                sprite_set_is_draw(sprite_y2_x1_face_1, false);
                sprite_set_is_draw(sprite_y2_x1_side_1, false);
                sprite_set_is_draw(sprite_y2_x1_face_2, false);
                sprite_set_is_draw(sprite_y2_x1_side_2, false);
                if (value == 1)
                {
                    sprite_set_is_draw(sprite_y2_x1_face_1, true);
                    sprite_set_is_draw(sprite_y2_x1_side_1, true);
                }
                else if (value == 2)
                {
                    sprite_set_is_draw(sprite_y2_x1_face_2, true);
                    sprite_set_is_draw(sprite_y2_x1_side_2, true);
                }
            }
            else if (i == 9)
            {
                sprite_set_is_draw(sprite_y2_x2_side_1, false);
                sprite_set_is_draw(sprite_y2_x2_side_2, false);
                if (value == 1)
                    sprite_set_is_draw(sprite_y2_x2_side_1, true);
                else if (value == 2)
                    sprite_set_is_draw(sprite_y2_x2_side_2, true);
            }
            else if (i == 10)
            {
                sprite_set_is_draw(sprite_y3_xm2_face_1, false);
                sprite_set_is_draw(sprite_y3_xm2_side_1, false);
                sprite_set_is_draw(sprite_y3_xm2_face_2, false);
                sprite_set_is_draw(sprite_y3_xm2_side_2, false);
                if (value == 1)
                {
                    sprite_set_is_draw(sprite_y3_xm2_face_1, true);
                    sprite_set_is_draw(sprite_y3_xm2_side_1, true);
                }
                else if (value == 2)
                {
                    sprite_set_is_draw(sprite_y3_xm2_face_2, true);
                    sprite_set_is_draw(sprite_y3_xm2_side_2, true);
                }
            }
            else if (i == 11)
            {
                sprite_set_is_draw(sprite_y3_xm1_face_1, false);
                sprite_set_is_draw(sprite_y3_xm1_side_1, false);
                sprite_set_is_draw(sprite_y3_xm1_face_2, false);
                sprite_set_is_draw(sprite_y3_xm1_side_2, false);
                if (value == 1)
                {
                    sprite_set_is_draw(sprite_y3_xm1_face_1, true);
                    sprite_set_is_draw(sprite_y3_xm1_side_1, true);
                }
                else if (value == 2)
                {
                    sprite_set_is_draw(sprite_y3_xm1_face_2, true);
                    sprite_set_is_draw(sprite_y3_xm1_side_2, true);
                }
            }
            else if (i == 12)
            {
                sprite_set_is_draw(sprite_y3_x0_face_1, false);
                sprite_set_is_draw(sprite_y3_x0_face_2, false);
                if (value == 1)
                    sprite_set_is_draw(sprite_y3_x0_face_1, true);
                else if (value == 2)
                    sprite_set_is_draw(sprite_y3_x0_face_2, true);
            }
            else if (i == 13)
            {
                sprite_set_is_draw(sprite_y3_x1_face_1, false);
                sprite_set_is_draw(sprite_y3_x1_side_1, false);
                sprite_set_is_draw(sprite_y3_x1_face_2, false);
                sprite_set_is_draw(sprite_y3_x1_side_2, false);
                if (value == 1)
                {
                    sprite_set_is_draw(sprite_y3_x1_face_1, true);
                    sprite_set_is_draw(sprite_y3_x1_side_1, true);
                }
                else if (value == 2)
                {
                    sprite_set_is_draw(sprite_y3_x1_face_2, true);
                    sprite_set_is_draw(sprite_y3_x1_side_2, true);
                }
            }
            else if (i == 14)
            {
                sprite_set_is_draw(sprite_y3_x2_face_1, false);
                sprite_set_is_draw(sprite_y3_x2_side_1, false);
                sprite_set_is_draw(sprite_y3_x2_face_2, false);
                sprite_set_is_draw(sprite_y3_x2_side_2, false);
                if (value == 1)
                {
                    sprite_set_is_draw(sprite_y3_x2_face_1, true);
                    sprite_set_is_draw(sprite_y3_x2_side_1, true);
                }
                else if (value == 2)
                {
                    sprite_set_is_draw(sprite_y3_x2_face_2, true);
                    sprite_set_is_draw(sprite_y3_x2_side_2, true);
                }
            }
        }
    }

    is_dirty_render_texture_main = true;
}
