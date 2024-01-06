#include <stdio.h>

#include <vector>

#include "raylib.h"
int main(void) {
    InitWindow(1104, 621, "attractor");
    // Define the camera to look into our 3d world
    Camera3D camera = {0};
    camera.position = (Vector3){10.0f, 10.0f, 10.0f};  // Camera position
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};       // Camera looking at point
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};           // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                               // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;            // Camera projection type
    DisableCursor();

    // attractor base
    int i = 0;
    float x, y, z, dx, dy, dz;
    float dt = 0.01;
    float sigma = 10.0;
    float ro = 28.0;
    float beta = 8.0 / 3.0;
    x = 0.1;
    y = 0;
    z = 0;

    int hue = 0;
    // Color color = ;
    std::vector<Vector3> pointAray;
    while (!WindowShouldClose()) {
        dx = sigma * (y - x) * dt;
        dy = x * (ro - z) * dt;
        dz = (x * y - beta * z) * dt;
        x = x + dx;
        y = y + dy;
        z = z + dz;
        Vector3 coords = {x, y, z};
        pointAray.push_back(coords);

        UpdateCamera(&camera, CAMERA_FREE);
        // begin drawing
        BeginDrawing();
        ClearBackground(BLACK);
        // cammera shit
        BeginMode3D(camera);
        for (const auto& pointcoords : pointAray) {
            DrawSphere(pointcoords, 0.1, ColorFromHSV(hue, 1, 1));  // drawing sphere
            hue += 1;
            if (hue > 360) {
                hue = 0;
            };
        }
        EndMode3D();  // end cammera
        DrawFPS(0, 0);
        EndDrawing();  // end drawing
    };
    CloseWindow();
    return 0;
};