//
//  ball.hpp
//  ping
//
//  Created by Nicole Lopez on 3/14/24.
//

#ifndef Ball_h
#define Ball_h

class Ball {
public:
    Ball(float x, float y, float radius = 40.0);
    void draw();
    void move();
    float getX();
    float getY();
    float getRadius();
    void reverseX();
    void reverseY();
    void reset(float newX, float newY);
    void collidesWith();

private:
    float x, y, radius, dx, dy;
};

#endif /* Ball_h */

