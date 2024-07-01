#include <stdio.h>

#include <vector>

#include "raylib.h"

int main(void) {
  // Initialization
  InitWindow(800, 450, "attractor");

  // cammera initialization shit
  Camera3D camera = {{0}};
  camera.position = (Vector3){10.0f, 10.0f, 10.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  // not showing cursor and shit
  DisableCursor();

  // setting up varaibles and stuff
  const float dt = 0.01f;
  const float sigma = 10.0f;
  const float ro = 28.0f;
  const float beta = 8.0f / 3.0f;

  float x = 0.1f, y = 0.0f, z = 0.0f;

  std::vector<Vector3>
      pointArray;  // initializing dynamic array to store points position to
                   // redrawing wont fuck it self
  while (!WindowShouldClose()) {
    // Attractor calculations

    // differentail equations
    float dx = sigma * (y - x) * dt;
    float dy = x * (ro - z) * dt;
    float dz = (x * y - beta * z) * dt;

    x += dx;
    y += dy;
    z += dz;

    pointArray.push_back({x, y, z});  // adding the points to the array

    // Camera update
    UpdateCamera(&camera, CAMERA_FREE);

    // Drawing
    BeginDrawing();
    ClearBackground(BLACK);  // the background is a black

    BeginMode3D(camera);
    for (int i = 0; i < pointArray.size() - 1; ++i) {
      DrawLine3D(pointArray[i], pointArray[i + 1], BLUE);
    }
    EndMode3D();

    DrawFPS(0, 0);  // this number gives me pain
    EndDrawing();
  }
  // deinitialization
  CloseWindow();
  return 0;
}