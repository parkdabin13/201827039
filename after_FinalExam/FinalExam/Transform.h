#pragma once

#include "Object.h"

namespace Transform
{
    struct Vertex
    {
        float x;
        float y;
    };

    struct Vector
    {
        float x_meter;
        float y_meter;
    };

    Vertex MoveVertex(Vertex point, Vector meter);
    Vertex RotateVertex(Vertex point, float angle_degree);
    Vertex ScaleVertex(Vertex point, Vector meter);
};
void EnemyPosition(float& x, float speed, float deltaTime);
void StarPosition(float& x, float speed, float deltaTime);
void resetEnemyPositions(EnemyBlock& enemy, float resetThreshold);
void resetStarPosition(float& x, float resetThreshold, float newX);
void GravityJump(float& posY, float& velocityY, bool& isJumping, float gravity, float deltaTime);
float random(float min, float max);
