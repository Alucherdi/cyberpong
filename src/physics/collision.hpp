#pragma once

#include "entities/player.hpp"
#include <raylib.h>
#include <iostream>

inline void resolve_col(player& p, Rectangle& b) {
    float xoverlap =
        std::min(p.rec.x + p.rec.width, b.x + b.width) -
        std::max(p.rec.x, b.x);

    float yoverlap =
        std::min(p.rec.y + p.rec.height, b.y + b.height) -
        std::max(p.rec.y, b.y);

    if (xoverlap < yoverlap) {
        if (p.rec.x < b.x) {
            p.rec.x -= xoverlap;
        } else {
            p.rec.x += xoverlap;
        }
    } else {
        if (p.rec.y < b.y) {
            p.rec.y -= yoverlap;
        } else {
            p.rec.y += yoverlap;
        }
        p.vel.y = 0;
        p.is_grounded = true;
    }
}
