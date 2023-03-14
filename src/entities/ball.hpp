#pragma once
#include "entities/entity.hpp"
#include "setup/screen.hpp"
#include <iostream>
#include <raylib.h>

struct ball { 
    Vector2 pos = { 400.0f, 400.0f };
    Vector2 vel = { -160.0f, -80.0f };

    float size = 10.0f;

    float bounce_force = 400.0f;

    void draw() {
        DrawCircle(pos.x, pos.y, size, RED);
    }

    void update(float delta, Rectangle p) {
        if (vel.x < 0) {
            if (CheckCollisionCircleRec(pos, size, p)) {
                vel.x *= -1;

                if ((p.y + (p.height / 2)) < pos.y) vel.y += 250.0f;
                else vel.y -= 250.0f;
            }
        } else {
            if (pos.x >= screen::width) {
                vel.x *= -1;
            }
        }

        vel.y += 5.0f;
        pos.x += vel.x * delta;
        pos.y += vel.y * delta;
    }

    void handle_bounce() {
        vel.y = -bounce_force;
    }

};
