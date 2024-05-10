//
//  game.cpp
//  ping
//
//  Created by Nicole Lopez on 3/14/24.
//
#define GL_SILENCE_DEPRECATION
#include "game.hpp"
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <iostream>


// Static instance pointer to the Game object
game* game::staticInstance = nullptr;

game::game(int screenWidth, int screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight),
      leftPaddle(50, screenHeight / 2, 10, 80), rightPaddle(screenWidth - 50, screenHeight / 2, 10, 80),
      ball(screenWidth / 2, screenHeight / 2, 10),
      leftScore(0), rightScore(0), isLeftPaddleClicked(false), isRightPaddleClicked(false) {
    staticInstance = this; // Initialize staticInstance with this
}

void game::start() {
    glutDisplayFunc(displayWrapper); // Use the static wrapper function as the callback
    glutTimerFunc(16, game::updateWrapper, 0);// Use the static wrapper function for update
    glutKeyboardFunc(keyboardWrapper);
    glutMouseFunc(mouseClickWrapper); // Register mouse click function
    glutMotionFunc(mouseMoveWrapper); // Register mouse move function
    glutMainLoop();
}

void game::update(int value) {
    ball.move();

    // Ball collision with top and bottom edges
    if (ball.getY() + ball.getRadius() > screenHeight || ball.getY() - ball.getRadius() < 0) {
        ball.reverseY();
    }

    // Ball collision with paddles
    if ((ball.getX() - ball.getRadius() <= leftPaddle.getX() + leftPaddle.getWidth() / 2) &&
        (ball.getY() >= leftPaddle.getY() - leftPaddle.getHeight() / 2) &&
        (ball.getY() <= leftPaddle.getY() + leftPaddle.getHeight() / 2)) {
        ball.reverseX();
    }

    if ((ball.getX() + ball.getRadius() >= rightPaddle.getX() - rightPaddle.getWidth() / 2) &&
        (ball.getY() >= rightPaddle.getY() - rightPaddle.getHeight() / 2) &&
        (ball.getY() <= rightPaddle.getY() + rightPaddle.getHeight() / 2)) {
        ball.reverseX();
    }

    // Ball out of bounds (score)
    if (ball.getX() - ball.getRadius() < 0) {
        rightScore++;
        ball.reset(screenWidth / 2, screenHeight / 2); // Reset ball position
    } else if (ball.getX() + ball.getRadius() > screenWidth) {
        leftScore++;
        ball.reset(screenWidth / 2, screenHeight / 2); // Reset ball position
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateWrapper, 0); // Update every 16 milliseconds (approximately 60 frames per second)
}
void game::drawScore()
{
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
        glRasterPos2f(screenWidth / 2 - 20, screenHeight - 30); // Position the text
        std::string scoreText = "Left: " + std::to_string(leftScore) + "  Right: " + std::to_string(rightScore);
        for (char c : scoreText) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c); // Draw each character of the score text
        }
}

void game::displayWrapper() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw paddles
    glColor3f(1.0, 1.0, 1.0); // White color
    glLoadIdentity();
    staticInstance->leftPaddle.draw();
    staticInstance->rightPaddle.draw();

    // Draw ball
    glColor3f(1.0, 0.0, 0.0); // Red color
    staticInstance->ball.draw();
    
    staticInstance ->drawScore();
    glutSwapBuffers();
}

void game::keyboardWrapper(unsigned char key, int x, int y) {
    // Handle keyboard input if needed
    switch(key) {
        case 'q':
            exit(0); // Quit the game when 'q' is pressed
            break;
        default:
            break;
    }
}

void game::mouseClickWrapper(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Handle left mouse button click
        staticInstance->isLeftPaddleClicked = true;
        staticInstance->isRightPaddleClicked = false; // Ensure right paddle click is false
        std::cout << "Left mouse button clicked" << std::endl;
    } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        // Handle right mouse button click
        staticInstance->isRightPaddleClicked = true;
        staticInstance->isLeftPaddleClicked = false; // Ensure left paddle click is false
        std::cout << "Right mouse button clicked" << std::endl;
    }
}



void game::mouseMoveWrapper(int x, int y) {
    std::cout << "Mouse moved to (" << x << ", " << y << ")" << std::endl;

    if (staticInstance->isLeftPaddleClicked) {
        // Update paddle position based on mouse movement
        staticInstance->leftPaddle.setY(static_cast<float>(y));
        std::cout << "Left paddle moved to Y = " << y << std::endl;
    } else if (staticInstance->isRightPaddleClicked) {
        // Update right paddle position based on mouse movement
        staticInstance->rightPaddle.setY(static_cast<float>(y));
        std::cout << "Right paddle moved to Y = " << y << std::endl;
    }
}



void game::updateWrapper(int value) {
    // Implementation of updateWrappe
    staticInstance->update(value);

        // Redraw the screen
        glutPostRedisplay();

        // Set the timer for the next update
        glutTimerFunc(16, game::updateWrapper, 0);
    }










