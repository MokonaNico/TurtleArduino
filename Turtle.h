/*
  Turtle.h - Library for controlling a turtle compatible with Elegoo TFT screen.
  Created by MokonaNico & CyberGally, 17-01-21.
  Released into the public domain.
*/

#ifndef Turtle_h
#define Turtle_h

#include <Elegoo_GFX.h>  
#include <Elegoo_TFTLCD.h>

class Turtle{
  public:
    Turtle(double init_x, double init_y, double init_rotation, Elegoo_TFTLCD* _tft);
    void setColor(uint16_t new_color);
    void moveForward(double distance);
    void moveBackward(double distance);
    void turnRight(double degree);
    void turnLeft(double degree);
    void teleport(double new_x, double new_y);
    void moveTo(double posX, double posY);
    void penUp();
    void penDown();
    void clearScreen(uint16_t screen_color);
    void setRotation(double degree);

  private:
    double x;
    double y;
    double rotation;
    bool penIsDown;
    uint16_t color;
    Elegoo_TFTLCD* tft;
    void moveInADirection(double distance, int dir);
};
#endif //Turtle_h
