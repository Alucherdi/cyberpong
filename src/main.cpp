#include "entities/ball.hpp"
#include "raylib.h"
#include "setup/screen.hpp"
#include "world/solids.hpp"
#include "entities/player.hpp"

int main() {
    player p;
    world w;
    ball b;

    InitWindow(screen::width, screen::height, screen::title);

    SetTargetFPS(144);

    while (!WindowShouldClose()) {
        p.handle_inputs(GetFrameTime());
        w.handle_col(p, b);
        b.update(GetFrameTime(), p.rec);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        p.draw();
        w.draw();
        b.draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
