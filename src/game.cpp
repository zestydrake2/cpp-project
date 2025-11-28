#include <iostream>
#include <string>
#include <memory>
#include <raylib.h>

/*   -- notes: --

1. I havent added in any form of drag which is why you will often see the ball rolling back and forth repeatedly.

2. Im most likely not going to update this since it is just a short project i made while i was bored.

*/



int main(){
   // initializing vars
    float ballX = 400.0f;
    float ballY = 300.0f;
    float vx = 0.0f;
    float vy = 0.0f;
    float radius = 30;
    float gravity = 9.8f;
    float elasticity = 0.8f;
    int boxWidth = 800;
    int boxHeight = 600;
    Camera2D camera = { 0 };
    camera.target = { boxWidth / 2.0f, boxHeight / 2.0f };
    camera.offset = { boxWidth / 2.0f, boxHeight / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
   


    SetTargetFPS(60);
    InitWindow(boxWidth, boxHeight, "2D PHYSICS SIM");
    
    // da game loop
    while (! WindowShouldClose()){
        Vector2 mousePos = GetMousePosition();
        
        // mousePos uses screen coordinates so we convert it to world coordinates.
        Vector2 worldmousePos = GetScreenToWorld2D(mousePos, camera);
        
        
        
        // warning the simulator is intended to be ran at 60fps since deltatime is only partially used.
        float dt = GetFrameTime();
        
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(camera);
        DrawCircle(ballX, ballY, radius, RED);

       // adds gravity (9.8) to the y velocity, in raylib positive y is down and negative is up.
        vy += gravity;

        //ball position updates based on the velocity.
        ballX += vx * dt;
        ballY += vy* dt;


        // lets u pick up the ball using your cursor. it is a bit floaty
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && worldmousePos.x >= ballX - radius - 15 && 
        worldmousePos.x <= ballX + radius + 15 && 
        worldmousePos.y >= ballY - radius - 15 && 
        worldmousePos.y <= ballY+ radius + 15){
            ballX = worldmousePos.x ;
            ballY = worldmousePos.y;
            vx = 0;
            vy = 0;
        }

    


        // detects the ball hitting the floor and reverses the velocity multiplied with the elasticity (0.9).
        if (ballY + radius > boxHeight){
        ballY -= ballY + radius - boxHeight;
        vy = -vy * elasticity;
        }
        // detects the ball hitting the ceiling.
        if (ballY - radius < 5){
            ballY = radius + 5;
            vy = -vy * elasticity;
        }
        // detects ball hitting the right wall.
        if  (ballX + radius >= boxWidth){
            ballX = boxWidth - radius;
            vx = -vx * elasticity;
        }
        // detects the ball hitting the left wall. 
        if (ballX - radius <= 5){
            ballX = radius + 5;
            vx = -vx * elasticity;
        }
        
        
        // adds force to a certain direction.
        
        if (IsKeyPressed(KEY_W)){
            vy -= 250.0f;
        }
        if (IsKeyPressed(KEY_S)){
            vy += 250.0f;
        }
        if (IsKeyPressed(KEY_D)){
            vx += 250.0f;
        }
        if (IsKeyPressed(KEY_A)){
            vx -= 250.0f;
        }
        







        EndMode2D();
        DrawText("W, A, S, D to add force to ball", 10 , 10, 20, GREEN);
        EndDrawing();
        if (IsKeyPressed(KEY_ESCAPE)){
            CloseWindow();
        }
    }
    CloseWindow();

}