//
//  game.hpp
//  ping
//
//  Created by Nicole Lopez on 3/14/24.
//

#ifndef Game_h
#define Game_h

#include "Paddle.hpp"
#include "Ball.hpp"

class game {
public:
    game(int screenWidth, int screenHeight);
    void start();
    void update(int value);
    void display();
    static void displayWrapper();
    static void mouseClickWrapper(int button, int state, int x, int y);
    static void keyboardWrapper(unsigned char key, int x, int y);
    static void mouseMoveWrapper(int x, int y);
    static void updateWrapper(int value);
    void drawScore();

private:
    int screenWidth, screenHeight;
    Paddle leftPaddle, rightPaddle;
    Ball ball;
    int leftScore;
    int rightScore;
    static game* staticInstance;
    bool isLeftPaddleClicked;
    bool isRightPaddleClicked;

    
    
};

#endif /* Game_h */

