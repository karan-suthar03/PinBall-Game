#include <iostream>
#include <raylib.h>
#include <vector>
#include "Ball.h"

void addBallAtPosition(std::vector<PB_Physics::Ball>& balls, const Vec2& position) {
    PB_Physics::Ball newBall;
    newBall.body.position = position;
    newBall.body.mass = 1.0f;
	newBall.body.velocity = Vec2(GetRandomValue(-100, 100), GetRandomValue(-100, 100));
    balls.push_back(newBall);
}

int main(){

    InitWindow(800, 600, "pinball game");

	std::vector<PB_Physics::Ball> balls;

    while (!WindowShouldClose()) {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
			addBallAtPosition(balls, Vec2(GetMouseX(), GetMouseY()));
		}

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (auto& ball : balls) {
            Vec2 force(0, 360);
            force = force * ball.body.mass;
            ball.body.AddForce(force);
            ball.body.Integrate(GetFrameTime());

            if (ball.body.position.y + ball.radius >= 600) {
                ball.body.position.y = 600 - ball.radius;
                ball.body.velocity.y *= -1.0f;
            }

            ball.draw();
        }

        EndDrawing();
    }

    return 0;
}