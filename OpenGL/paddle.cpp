//
//  paddle.cpp
//  ping
//
//  Created by Nicole Lopez on 3/14/24.
//
#define GL_SILENCE_DEPRECATION
#include "paddle.hpp"
#include <OpenGL/gl.h>

Paddle::Paddle(float x, float y, float width, float height)
    : x(x), y(y), width(width), height(height), stepSize(0.9f) {}

void Paddle::draw() {
    glBegin(GL_QUADS);
    glVertex2f(x - width / 2, y - height / 2);
    glVertex2f(x + width / 2, y - height / 2);
    glVertex2f(x + width / 2, y + height / 2);
    glVertex2f(x - width / 2, y + height / 2);
    glEnd();
}

void Paddle::moveUp(float stepSize) {
    y += stepSize; // Adjust the speed using the provided step size
}

void Paddle::moveDown(float stepSize) {
    y -= stepSize; // Adjust the speed using the provided step size
}
void Paddle::setY(float newY){
    y = newY;
}

float Paddle::getX() {
    return x;
}

float Paddle::getY() {
    return y;
}

float Paddle::getWidth() {
    return width;
}

float Paddle::getHeight() {
    return height;
}


