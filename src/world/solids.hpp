#pragma once
#include "entities/ball.hpp"
#include "physics/collision.hpp"
#include "entities/player.hpp"
#include <iostream>
#include <vector>

#include <raylib.h>
using namespace std;

struct world {
    vector<Rectangle> solids {
        { 0.0f, 430.0f, 800.0f, 30.0f },
        { 40.0f, 390.0f, 80.0f, 8.0f },
        { 60.0f, 350.0f, 80.0f, 8.0f },
    };

    void handle_col(player& p, ball& b) {
        for (Rectangle solid : solids) {
            if (CheckCollisionRecs(p.rec, solid)) {
                resolve_col(p, solid);
            }
        }

        if (CheckCollisionCircleRec(b.pos, b.size, solids[0])) {
            b.handle_bounce();
        }
    }

    void draw() {
        for (Rectangle solid : solids) {
            DrawRectangleRec(solid, BLUE);
        }
    }
};
