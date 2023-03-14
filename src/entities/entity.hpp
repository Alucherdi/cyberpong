#pragma once
#include <raylib.h>

struct entity {
    Rectangle rec;
    Vector2 vel;
    Color color;

    void draw() {
        DrawRectangleRec(rec, color);
    }
};
