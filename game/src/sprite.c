#include "sprite.h"

#include <float.h>

struct sprite sprite_create_1(bool is_draw, Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint)
{
    struct sprite sprite = (struct sprite){ 0 };

    sprite.is_draw = is_draw;
    sprite.texture = texture;
    sprite.source = source;
    sprite.dest = dest;
    sprite.origin = origin;
    sprite.rotation = rotation;
    sprite.tint = tint;

    return sprite;
}

struct sprite sprite_create_2(Texture2D texture, float dest_x, float dest_y, bool is_flip)
{
    Rectangle source = (Rectangle){ 0, 0, is_flip ? -(float)texture.width : (float)texture.width, (float)texture.height };
    Rectangle dest = (Rectangle){ dest_x, dest_y, (float)texture.width, (float)texture.height };
    Vector2 origin = (Vector2){ 0, 0 };

    return sprite_create_1(true, texture, source, dest, origin, 0, WHITE);
}



bool sprite_get_is_draw(struct sprite * sprite)
{
    return sprite->is_draw;
}

Texture2D sprite_get_texture(struct sprite * sprite)
{
    return sprite->texture;
}

Rectangle sprite_get_source(struct sprite * sprite)
{
    return sprite->source;
}
float sprite_get_source_x(struct sprite * sprite)
{
    return sprite->source.x;
}
float sprite_get_source_y(struct sprite * sprite)
{
    return sprite->source.y;
}
float sprite_get_source_width(struct sprite * sprite)
{
    return sprite->source.width;
}
float sprite_get_source_height(struct sprite * sprite)
{
    return sprite->source.height;
}
Vector2 sprite_get_source_position(struct sprite * sprite)
{
    return (Vector2) { sprite->source.x, sprite->source.y };
}
Vector2 sprite_get_source_size(struct sprite * sprite)
{
    return (Vector2) { sprite->source.width, sprite->source.height };
}

Rectangle sprite_get_dest(struct sprite * sprite)
{
    return sprite->dest;
}
float sprite_get_dest_x(struct sprite * sprite)
{
    return sprite->dest.x;
}
float sprite_get_dest_y(struct sprite * sprite)
{
    return sprite->dest.y;
}
float sprite_get_dest_width(struct sprite * sprite)
{
    return sprite->dest.width;
}
float sprite_get_dest_height(struct sprite * sprite)
{
    return sprite->dest.height;
}
Vector2 sprite_get_dest_position(struct sprite * sprite)
{
    return (Vector2) { sprite->dest.x, sprite->dest.y };
}
Vector2 sprite_get_dest_size(struct sprite * sprite)
{
    return (Vector2) { sprite->dest.width, sprite->dest.height };
}

Vector2 sprite_get_origin(struct sprite * sprite)
{
    return sprite->origin;
}
float sprite_get_origin_x(struct sprite * sprite)
{
    return sprite->origin.x;
}
float sprite_get_origin_y(struct sprite * sprite)
{
    return sprite->origin.y;
}

float sprite_get_rotation(struct sprite * sprite)
{
    return sprite->rotation;
}

Color sprite_get_tint(struct sprite * sprite)
{
    return sprite->tint;
}
unsigned char sprite_get_tint_r(struct sprite * sprite)
{
    return sprite->tint.r;
}
unsigned char sprite_get_tint_g(struct sprite * sprite)
{
    return sprite->tint.g;
}
unsigned char sprite_get_tint_b(struct sprite * sprite)
{
    return sprite->tint.b;
}
unsigned char sprite_get_tint_a(struct sprite * sprite)
{
    return sprite->tint.a;
}



void sprite_set_is_draw(struct sprite * sprite, bool is_draw)
{
    sprite->is_draw = is_draw;
}

void sprite_set_texture(struct sprite * sprite, Texture2D texture)
{
    sprite->texture = texture;
}

void sprite_set_source_x(struct sprite * sprite, float source_x)
{
    sprite->source.x = source_x;
}
void sprite_set_source_y(struct sprite * sprite, float source_y)
{
    sprite->source.y = source_y;
}
void sprite_set_source_width(struct sprite * sprite, float source_width)
{
    sprite->source.width = source_width;
}
void sprite_set_source_height(struct sprite * sprite, float source_height)
{
    sprite->source.height = source_height;
}
void sprite_set_source_1(struct sprite * sprite, float source_x, float source_y, float source_width, float source_height)
{
    sprite->source.x = source_x;
    sprite->source.y = source_y;
    sprite->source.width = source_width;
    sprite->source.height = source_height;
}
void sprite_set_source_2(struct sprite * sprite, Rectangle source)
{
    sprite->source = source;
}
void sprite_set_source_position_1(struct sprite * sprite, float source_x, float source_y)
{
    sprite->source.x = source_x;
    sprite->source.y = source_y;
}
void sprite_set_source_position_2(struct sprite * sprite, Vector2 source_position)
{
    sprite->source.x = source_position.x;
    sprite->source.y = source_position.y;
}
void sprite_set_source_size_1(struct sprite * sprite, float source_width, float source_height)
{
    sprite->source.width = source_width;
    sprite->source.height = source_height;
}
void sprite_set_source_size_2(struct sprite * sprite, Vector2 source_size)
{
    sprite->source.width = source_size.x;
    sprite->source.height = source_size.y;
}

void sprite_set_dest_x(struct sprite * sprite, float dest_x)
{
    sprite->dest.x = dest_x;
}
void sprite_set_dest_y(struct sprite * sprite, float dest_y)
{
    sprite->dest.y = dest_y;
}
void sprite_set_dest_width(struct sprite * sprite, float dest_width)
{
    sprite->dest.width = dest_width;
}
void sprite_set_dest_height(struct sprite * sprite, float dest_height)
{
    sprite->dest.height = dest_height;
}
void sprite_set_dest_1(struct sprite * sprite, float dest_x, float dest_y, float dest_width, float dest_height)
{
    sprite->dest.x = dest_x;
    sprite->dest.y = dest_y;
    sprite->dest.width = dest_width;
    sprite->dest.height = dest_height;
}
void sprite_set_dest_2(struct sprite * sprite, Rectangle dest)
{
    sprite->dest = dest;
}
void sprite_set_dest_position_1(struct sprite * sprite, float dest_x, float dest_y)
{
    sprite->dest.x = dest_x;
    sprite->dest.y = dest_y;
}
void sprite_set_dest_position_2(struct sprite * sprite, Vector2 dest_position)
{
    sprite->dest.x = dest_position.x;
    sprite->dest.y = dest_position.y;
}
void sprite_set_dest_size_1(struct sprite * sprite, float dest_width, float dest_height)
{
    sprite->dest.width = dest_width;
    sprite->dest.height = dest_height;
}
void sprite_set_dest_size_2(struct sprite * sprite, Vector2 dest_size)
{
    sprite->dest.width = dest_size.x;
    sprite->dest.height = dest_size.y;
}

void sprite_set_origin_x(struct sprite * sprite, float origin_x)
{
    sprite->origin.x = origin_x;
}
void sprite_set_origin_y(struct sprite * sprite, float origin_y)
{
    sprite->origin.y = origin_y;
}
void sprite_set_origin_1(struct sprite * sprite, float origin_x, float origin_y)
{
    sprite->origin.x = origin_x;
    sprite->origin.y = origin_y;
}
void sprite_set_origin_2(struct sprite * sprite, Vector2 origin)
{
    sprite->origin = origin;
}

void sprite_set_rotation(struct sprite * sprite, float rotation)
{
    sprite->rotation = rotation;
}

void sprite_set_tint_r(struct sprite * sprite, unsigned char tint_r)
{
    sprite->tint.r = tint_r;
}
void sprite_set_tint_g(struct sprite * sprite, unsigned char tint_g)
{
    sprite->tint.g = tint_g;
}
void sprite_set_tint_b(struct sprite * sprite, unsigned char tint_b)
{
    sprite->tint.b = tint_b;
}
void sprite_set_tint_a(struct sprite * sprite, unsigned char tint_a)
{
    sprite->tint.a = tint_a;
}
void sprite_set_tint_1(struct sprite * sprite, unsigned char tint_r, unsigned char tint_g, unsigned char tint_b, unsigned char tint_a)
{
    sprite->tint.r = tint_r;
    sprite->tint.g = tint_g;
    sprite->tint.b = tint_b;
    sprite->tint.a = tint_a;
}
void sprite_set_tint_2(struct sprite * sprite, Color tint)
{
    sprite->tint = tint;
}



void sprite_toggle_is_draw(struct sprite * sprite)
{
    sprite_set_is_draw(sprite, !sprite_get_is_draw(sprite));
}

void sprite_translate_source_x(struct sprite * sprite, double source_x_translation)
{
    source_x_translation = source_x_translation < (double)-FLT_MAX * 2 ? (double)-FLT_MAX * 2 : source_x_translation >(double)FLT_MAX * 2 ? (double)FLT_MAX * 2 : source_x_translation;
    double source_x = sprite_get_source_x(sprite) + source_x_translation;
    sprite_set_source_x(sprite, source_x < -FLT_MAX ? -FLT_MAX : source_x > FLT_MAX ? FLT_MAX : (float)source_x);
}
void sprite_translate_source_y(struct sprite * sprite, double source_y_translation)
{
    source_y_translation = source_y_translation < (double)-FLT_MAX * 2 ? (double)-FLT_MAX * 2 : source_y_translation >(double)FLT_MAX * 2 ? (double)FLT_MAX * 2 : source_y_translation;
    double source_y = sprite_get_source_y(sprite) + source_y_translation;
    sprite_set_source_y(sprite, source_y < -FLT_MAX ? -FLT_MAX : source_y > FLT_MAX ? FLT_MAX : (float)source_y);
}
void sprite_translate_source_width(struct sprite * sprite, double source_width_translation)
{
    source_width_translation = source_width_translation < (double)-FLT_MAX * 2 ? (double)-FLT_MAX * 2 : source_width_translation >(double)FLT_MAX * 2 ? (double)FLT_MAX * 2 : source_width_translation;
    double source_width = sprite_get_source_width(sprite) + source_width_translation;
    sprite_set_source_width(sprite, source_width < -FLT_MAX ? -FLT_MAX : source_width > FLT_MAX ? FLT_MAX : (float)source_width);
}
void sprite_translate_source_height(struct sprite * sprite, double source_height_translation)
{
    source_height_translation = source_height_translation < (double)-FLT_MAX * 2 ? (double)-FLT_MAX * 2 : source_height_translation >(double)FLT_MAX * 2 ? (double)FLT_MAX * 2 : source_height_translation;
    double source_height = sprite_get_source_height(sprite) + source_height_translation;
    sprite_set_source_height(sprite, source_height < -FLT_MAX ? -FLT_MAX : source_height > FLT_MAX ? FLT_MAX : (float)source_height);
}
void sprite_translate_source(struct sprite * sprite, double source_x_translation, double source_y_translation, double source_width_translation, double source_height_translation)
{
    sprite_translate_source_x(sprite, source_x_translation);
    sprite_translate_source_y(sprite, source_y_translation);
    sprite_translate_source_width(sprite, source_width_translation);
    sprite_translate_source_height(sprite, source_height_translation);
}
void sprite_translate_source_position(struct sprite * sprite, double source_x_translation, double source_y_translation)
{
    sprite_translate_source_x(sprite, source_x_translation);
    sprite_translate_source_y(sprite, source_y_translation);
}
void sprite_translate_source_size(struct sprite * sprite, double source_width_translation, double source_height_translation)
{
    sprite_translate_source_width(sprite, source_width_translation);
    sprite_translate_source_height(sprite, source_height_translation);
}

void sprite_translate_dest_x(struct sprite * sprite, double dest_x_translation)
{
    dest_x_translation = dest_x_translation < (double)-FLT_MAX * 2 ? (double)-FLT_MAX * 2 : dest_x_translation >(double)FLT_MAX * 2 ? (double)FLT_MAX * 2 : dest_x_translation;
    double dest_x = sprite_get_dest_x(sprite) + dest_x_translation;
    sprite_set_dest_x(sprite, dest_x < -FLT_MAX ? -FLT_MAX : dest_x > FLT_MAX ? FLT_MAX : (float)dest_x);
}
void sprite_translate_dest_y(struct sprite * sprite, double dest_y_translation)
{
    dest_y_translation = dest_y_translation < (double)-FLT_MAX * 2 ? (double)-FLT_MAX * 2 : dest_y_translation >(double)FLT_MAX * 2 ? (double)FLT_MAX * 2 : dest_y_translation;
    double dest_y = sprite_get_dest_y(sprite) + dest_y_translation;
    sprite_set_dest_y(sprite, dest_y < -FLT_MAX ? -FLT_MAX : dest_y > FLT_MAX ? FLT_MAX : (float)dest_y);
}
void sprite_translate_dest_width(struct sprite * sprite, double dest_width_translation)
{
    dest_width_translation = dest_width_translation < (double)-FLT_MAX * 2 ? (double)-FLT_MAX * 2 : dest_width_translation >(double)FLT_MAX * 2 ? (double)FLT_MAX * 2 : dest_width_translation;
    double dest_width = sprite_get_dest_width(sprite) + dest_width_translation;
    sprite_set_dest_width(sprite, dest_width < -FLT_MAX ? -FLT_MAX : dest_width > FLT_MAX ? FLT_MAX : (float)dest_width);
}
void sprite_translate_dest_height(struct sprite * sprite, double dest_height_translation)
{
    dest_height_translation = dest_height_translation < (double)-FLT_MAX * 2 ? (double)-FLT_MAX * 2 : dest_height_translation >(double)FLT_MAX * 2 ? (double)FLT_MAX * 2 : dest_height_translation;
    double dest_height = sprite_get_dest_height(sprite) + dest_height_translation;
    sprite_set_dest_height(sprite, dest_height < -FLT_MAX ? -FLT_MAX : dest_height > FLT_MAX ? FLT_MAX : (float)dest_height);
}
void sprite_translate_dest(struct sprite * sprite, double dest_x_translation, double dest_y_translation, double dest_width_translation, double dest_height_translation)
{
    sprite_translate_dest_x(sprite, dest_x_translation);
    sprite_translate_dest_y(sprite, dest_y_translation);
    sprite_translate_dest_width(sprite, dest_width_translation);
    sprite_translate_dest_height(sprite, dest_height_translation);
}
void sprite_translate_dest_position(struct sprite * sprite, double dest_x_translation, double dest_y_translation)
{
    sprite_translate_dest_x(sprite, dest_x_translation);
    sprite_translate_dest_y(sprite, dest_y_translation);
}
void sprite_translate_dest_size(struct sprite * sprite, double dest_width_translation, double dest_height_translation)
{
    sprite_translate_dest_width(sprite, dest_width_translation);
    sprite_translate_dest_height(sprite, dest_height_translation);
}

void sprite_translate_origin_x(struct sprite * sprite, double origin_x_translation)
{
    origin_x_translation = origin_x_translation < (double)-FLT_MAX * 2 ? (double)-FLT_MAX * 2 : origin_x_translation >(double)FLT_MAX * 2 ? (double)FLT_MAX * 2 : origin_x_translation;
    double origin_x = sprite_get_origin_x(sprite) + origin_x_translation;
    sprite_set_origin_x(sprite, origin_x < (double)-FLT_MAX ? -FLT_MAX : origin_x > (double)FLT_MAX ? FLT_MAX : (float)origin_x);
}
void sprite_translate_origin_y(struct sprite * sprite, double origin_y_translation)
{
    origin_y_translation = origin_y_translation < (double)-FLT_MAX * 2 ? (double)-FLT_MAX * 2 : origin_y_translation >(double)FLT_MAX * 2 ? (double)FLT_MAX * 2 : origin_y_translation;
    double origin_y = sprite_get_origin_y(sprite) + origin_y_translation;
    sprite_set_origin_y(sprite, origin_y < (double)-FLT_MAX ? -FLT_MAX : origin_y > (double)FLT_MAX ? FLT_MAX : (float)origin_y);
}
void sprite_translate_origin(struct sprite * sprite, double origin_x_translation, double origin_y_translation)
{
    sprite_translate_origin_x(sprite, origin_x_translation);
    sprite_translate_origin_y(sprite, origin_y_translation);
}

void sprite_translate_rotation(struct sprite * sprite, double rotation_translation)
{
    rotation_translation = rotation_translation < (double)-FLT_MAX * 2 ? (double)-FLT_MAX * 2 : rotation_translation >(double)FLT_MAX * 2 ? (double)FLT_MAX * 2 : rotation_translation;
    double rotation = sprite_get_rotation(sprite) + rotation_translation;
    sprite_set_rotation(sprite, rotation < (double)-FLT_MAX ? -FLT_MAX : rotation > (double)FLT_MAX ? FLT_MAX : (float)rotation);
}

void sprite_translate_tint_r(struct sprite * sprite, short tint_r_translation)
{
    int tint_r = (int)sprite_get_tint_r(sprite) + tint_r_translation;
    sprite_set_tint_r(sprite, tint_r < 0 ? 0 : tint_r > 255 ? 255 : (unsigned char)tint_r);
}
void sprite_translate_tint_g(struct sprite * sprite, short tint_g_translation)
{
    int tint_g = (int)sprite_get_tint_g(sprite) + tint_g_translation;
    sprite_set_tint_g(sprite, tint_g < 0 ? 0 : tint_g > 255 ? 255 : (unsigned char)tint_g);
}
void sprite_translate_tint_b(struct sprite * sprite, short tint_b_translation)
{
    int tint_b = (int)sprite_get_tint_b(sprite) + tint_b_translation;
    sprite_set_tint_b(sprite, tint_b < 0 ? 0 : tint_b > 255 ? 255 : (unsigned char)tint_b);
}
void sprite_translate_tint_a(struct sprite * sprite, short tint_a_translation)
{
    int tint_a = (int)sprite_get_tint_a(sprite) + tint_a_translation;
    sprite_set_tint_a(sprite, tint_a < 0 ? 0 : tint_a > 255 ? 255 : (unsigned char)tint_a);
}
void sprite_translate_tint(struct sprite * sprite, short tint_r_translation, short tint_g_translation, short tint_b_translation, short tint_a_translation)
{
    sprite_translate_tint_r(sprite, tint_r_translation);
    sprite_translate_tint_g(sprite, tint_g_translation);
    sprite_translate_tint_b(sprite, tint_b_translation);
    sprite_translate_tint_a(sprite, tint_a_translation);
}



void sprite_draw(struct sprite * sprite)
{
    if (sprite_get_is_draw(sprite))
    {
        Texture2D texture = sprite_get_texture(sprite);
        Rectangle source = sprite_get_source(sprite);
        Rectangle dest = sprite_get_dest(sprite);
        Vector2 origin = sprite_get_origin(sprite);
        float rotation = sprite_get_rotation(sprite);
        Color tint = sprite_get_tint(sprite);
        DrawTexturePro(texture, source, dest, origin, rotation, tint);
    }
}
