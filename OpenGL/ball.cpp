//
//  ball.cpp
//  ping
//
//  Created by Nicole Lopez on 3/14/24.
//
//
#define GL_SILENCE_DEPRECATION
#include "ball.hpp"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <cmath>

Ball::Ball(float x, float y, float radius)
    : x(x), y(y), radius(40.0), dx(5.0), dy(5.0) {} // Adjust the speed as needed

void Ball::draw() {
    // Example of drawing a more 3D-like ball using colors
        const int numSegments = 30;
        const float radius = this->radius;

        glPushMatrix();
        glTranslatef(x, y, 0.0f);

        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.0f, 0.0f);  // Red color
        glVertex2f(0.0f, 0.0f);  // Center point

        for (int i = 0; i <= numSegments; ++i) {
            float angle = static_cast<float>(i) / static_cast<float>(numSegments) * 2.0f * 3.14159f;
            float x = radius * cos(angle);
            float y = radius * sin(angle);
            glColor3f(cos(angle), sin(angle), 0.5f);  // Color based on angle
            glVertex2f(x, y);
        }

        glEnd();

        glPopMatrix();
    
}


void Ball::move() {
    x += dx;
    y += dy;
}

float Ball::getX() {
    return x;
}

float Ball::getY() {
    return y;
}

float Ball::getRadius() {
    return radius;
}

void Ball::reverseX() {
    dx = -dx;
}

void Ball::reverseY() {
    dy = -dy;
}
void Ball::reset(float newX, float newY) {
    x = newX;
    y = newY;
    dx = 5.0; // Reset the ball's speed if needed
    dy = 5.0; // Reset the ball's speed if needed
}

