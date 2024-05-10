//
//  main.cpp
//  ping
//
//  Created by Nicole Lopez on 3/14/24.
//
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include "Game.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>

int screenWidth = 800;
int screenHeight = 600;

void init() {
    srand(static_cast<unsigned int>(time(NULL))); // Seed for random color generation

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, screenWidth, 0, screenHeight);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void updateBackground(int value) {
    // Calculate rainbow color components
    float r = static_cast<float>(rand()) / RAND_MAX;
    float g = static_cast<float>(rand()) / RAND_MAX;
    float b = static_cast<float>(rand()) / RAND_MAX;

    // Clear the color buffer with the rainbow color
    glClearColor(r, g, b, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Redraw the scene
    glutPostRedisplay();

    // Set a timer to call updateBackground again after a delay
    glutTimerFunc(1000 / 60, updateBackground, 0); // 60 FPS update rate
}
void display()
{
    glutSwapBuffers();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Pong Game");
    init();
    
    // Seed for random color generation
       srand(static_cast<unsigned int>(time(NULL)));

       // Set initial background color
       glClearColor(1.0, 1.0, 1.0, 1.0);
       glClear(GL_COLOR_BUFFER_BIT);
       glutSwapBuffers();
    

    glutTimerFunc(1000 / 120, updateBackground, 0);
    game game(screenWidth, screenHeight);
    glutDisplayFunc(game.displayWrapper);  // Use myGame's displayWrapper function
    glutKeyboardFunc(game.keyboardWrapper);
    glutMouseFunc(game.mouseClickWrapper);
    glutMotionFunc(game.mouseMoveWrapper);
    //glutTimerFunc(16, game.update, 0);
    game.start();
    
    glutMainLoop();

    return 0;
}


