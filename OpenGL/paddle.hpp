//
//  paddle.hpp
//  ping
//
//  Created by Nicole Lopez on 3/14/24.
//


#ifndef Paddle_h
#define Paddle_h

class Paddle {
public:
    Paddle(float x, float y, float width, float height);
    void draw();
    void moveUp(float stepSize);
    void moveDown(float stepSize);
    float getX();
    float getY();
    float getWidth();
    float getHeight();
    void move();
    void setY(float newY);

private:
    float x, y, width, height;
    float stepSize;
};

#endif /* Paddle_h */

