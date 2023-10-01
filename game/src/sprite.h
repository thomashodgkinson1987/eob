#ifndef SPRITE_H
#define SPRITE_H



#include "raylib.h"



struct sprite
{
    bool is_draw;
    Texture2D texture;
    Rectangle source;
    Rectangle dest;
    Vector2 origin;
    float rotation;
    Color tint;
};



struct sprite sprite_create_1(bool is_draw, Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint);
struct sprite sprite_create_2(Texture2D texture, float dest_x, float dest_y, bool is_flip);



bool sprite_get_is_draw(struct sprite * sprite);

Texture2D sprite_get_texture(struct sprite * sprite);

Rectangle sprite_get_source(struct sprite * sprite);
float sprite_get_source_x(struct sprite * sprite);
float sprite_get_source_y(struct sprite * sprite);
float sprite_get_source_width(struct sprite * sprite);
float sprite_get_source_height(struct sprite * sprite);
Vector2 sprite_get_source_position(struct sprite * sprite);
Vector2 sprite_get_source_size(struct sprite * sprite);

Rectangle sprite_get_dest(struct sprite * sprite);
float sprite_get_dest_x(struct sprite * sprite);
float sprite_get_dest_y(struct sprite * sprite);
float sprite_get_dest_width(struct sprite * sprite);
float sprite_get_dest_height(struct sprite * sprite);
Vector2 sprite_get_dest_position(struct sprite * sprite);
Vector2 sprite_get_dest_size(struct sprite * sprite);

Vector2 sprite_get_origin(struct sprite * sprite);
float sprite_get_origin_x(struct sprite * sprite);
float sprite_get_origin_y(struct sprite * sprite);

float sprite_get_rotation(struct sprite * sprite);

Color sprite_get_tint(struct sprite * sprite);
unsigned char sprite_get_tint_r(struct sprite * sprite);
unsigned char sprite_get_tint_g(struct sprite * sprite);
unsigned char sprite_get_tint_b(struct sprite * sprite);
unsigned char sprite_get_tint_a(struct sprite * sprite);



void sprite_set_is_draw(struct sprite * sprite, bool is_draw);

void sprite_set_texture(struct sprite * sprite, Texture2D texture);

void sprite_set_source_x(struct sprite * sprite, float source_x);
void sprite_set_source_y(struct sprite * sprite, float source_y);
void sprite_set_source_width(struct sprite * sprite, float source_width);
void sprite_set_source_height(struct sprite * sprite, float source_height);
void sprite_set_source_1(struct sprite * sprite, float source_x, float source_y, float source_width, float source_height);
void sprite_set_source_2(struct sprite * sprite, Rectangle source);
void sprite_set_source_position_1(struct sprite * sprite, float source_x, float source_y);
void sprite_set_source_position_2(struct sprite * sprite, Vector2 source_position);
void sprite_set_source_size_1(struct sprite * sprite, float source_width, float source_height);
void sprite_set_source_size_2(struct sprite * sprite, Vector2 source_size);

void sprite_set_dest_x(struct sprite * sprite, float dest_x);
void sprite_set_dest_y(struct sprite * sprite, float dest_y);
void sprite_set_dest_width(struct sprite * sprite, float dest_width);
void sprite_set_dest_height(struct sprite * sprite, float dest_height);
void sprite_set_dest_1(struct sprite * sprite, float dest_x, float dest_y, float dest_width, float dest_height);
void sprite_set_dest_2(struct sprite * sprite, Rectangle dest);
void sprite_set_dest_position_1(struct sprite * sprite, float dest_x, float dest_y);
void sprite_set_dest_position_2(struct sprite * sprite, Vector2 dest_position);
void sprite_set_dest_size_1(struct sprite * sprite, float dest_width, float dest_height);
void sprite_set_dest_size_2(struct sprite * sprite, Vector2 dest_size);

void sprite_set_origin_x(struct sprite * sprite, float origin_x);
void sprite_set_origin_y(struct sprite * sprite, float origin_x);
void sprite_set_origin_1(struct sprite * sprite, float origin_x, float origin_y);
void sprite_set_origin_2(struct sprite * sprite, Vector2 origin);

void sprite_set_rotation(struct sprite * sprite, float rotation);

void sprite_set_tint_r(struct sprite * sprite, unsigned char tint_r);
void sprite_set_tint_g(struct sprite * sprite, unsigned char tint_g);
void sprite_set_tint_b(struct sprite * sprite, unsigned char tint_b);
void sprite_set_tint_a(struct sprite * sprite, unsigned char tint_a);
void sprite_set_tint_1(struct sprite * sprite, unsigned char tint_r, unsigned char tint_g, unsigned char tint_b, unsigned char tint_a);
void sprite_set_tint_2(struct sprite * sprite, Color tint);




void sprite_toggle_is_draw(struct sprite * sprite);

void sprite_translate_source_x(struct sprite * sprite, double source_x_translation);
void sprite_translate_source_y(struct sprite * sprite, double source_y_translation);
void sprite_translate_source_width(struct sprite * sprite, double source_width_translation);
void sprite_translate_source_height(struct sprite * sprite, double source_height_translation);
void sprite_translate_source(struct sprite * sprite, double source_x_translation, double source_y_translation, double source_width_translation, double source_height_translation);
void sprite_translate_source_position(struct sprite * sprite, double source_x_translation, double source_y_translation);
void sprite_translate_source_size(struct sprite * sprite, double source_width_translation, double source_height_translation);

void sprite_translate_dest_x(struct sprite * sprite, double dest_x_translation);
void sprite_translate_dest_y(struct sprite * sprite, double dest_y_translation);
void sprite_translate_dest_width(struct sprite * sprite, double dest_width_translation);
void sprite_translate_dest_height(struct sprite * sprite, double dest_height_translation);
void sprite_translate_dest(struct sprite * sprite, double dest_x_translation, double dest_y_translation, double dest_width_translation, double dest_height_translation);
void sprite_translate_dest_position(struct sprite * sprite, double dest_x_translation, double dest_y_translation);
void sprite_translate_dest_size(struct sprite * sprite, double dest_width_translation, double dest_height_translation);

void sprite_translate_origin_x(struct sprite * sprite, double origin_x_translation);
void sprite_translate_origin_y(struct sprite * sprite, double origin_y_translation);
void sprite_translate_origin(struct sprite * sprite, double origin_x_translation, double origin_y_translation);

void sprite_translate_rotation(struct sprite * sprite, double rotation_translation);

void sprite_translate_tint_r(struct sprite * sprite, short tint_r_translation);
void sprite_translate_tint_g(struct sprite * sprite, short tint_g_translation);
void sprite_translate_tint_b(struct sprite * sprite, short tint_b_translation);
void sprite_translate_tint_a(struct sprite * sprite, short tint_a_translation);
void sprite_translate_tint(struct sprite * sprite, short tint_r_translation, short tint_g_translation, short tint_b_translation, short tint_a_translation);



void sprite_draw(struct sprite * sprite);



#endif
