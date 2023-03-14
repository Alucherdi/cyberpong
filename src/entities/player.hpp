#pragma once
#include <raylib.h>
#include <iostream>

struct player {
    Rectangle rec = { 10.0f, 400.0f, 12.0f, 22.0f };
    Vector2 vel = { 180.0f, 0.0f };
    bool is_grounded = false;

    float attack_max_cd = 4.0f;
    float attack_cd = 0.0f;


    void draw() {
        DrawRectangleRec(rec, GREEN);
    }

    void handle_inputs(float delta) {
        if (IsKeyDown(KEY_D)) rec.x += vel.x * delta;
        else if (IsKeyDown(KEY_A)) rec.x -= vel.x * delta;

        if (IsKeyDown(KEY_SPACE)) {
            vel.y = -200.0f;
        }

        vel.y += 8.0f;
        rec.y += vel.y * delta;

        if (IsKeyReleased(KEY_J)) {
            std::cout << "Attack\n";
        }
    }

};
