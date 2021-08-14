#include "Turtle.h"
#include <Elegoo_GFX.h>  
#include <Elegoo_TFTLCD.h>
#include <math.h>

Turtle::Turtle(double init_x, double init_y, double init_rotation, Elegoo_TFTLCD* _tft){
  x = init_x;
  y = init_y;
  rotation = radians(init_rotation);
  tft = _tft;
  color = 0xFFFF;
  penIsDown = true;
}

void Turtle::setColor(uint16_t new_color){
  color = new_color;
}

void Turtle::moveInADirection(double distance, int dir){
  double new_x, new_y;
  new_x = x + cos(rotation) * distance * dir;
  new_y = y + sin(rotation) * distance * dir;
  if (penIsDown)
    tft->drawLine(round(x),round(y),round(new_x),round(new_y),color);
  x = new_x;
  y = new_y;
}

void Turtle::moveForward(double distance){
  moveInADirection(distance,1);
}

void Turtle::moveBackward(double distance){
  moveInADirection(distance,-1);
}

void Turtle::turnRight(double degree){
  rotation += radians(degree);
}

void Turtle::turnLeft(double degree){
  rotation -= radians(degree);
}

void Turtle::setRotation(double degree){
  rotation = radians(degree);
}

void Turtle::moveTo(double posX, double posY){
  if (penIsDown)
    tft->drawLine(round(x),round(y),round(posX),round(posY),color);
  x = posX;
  y = posY;
}

void Turtle::teleport(double new_x, double new_y){
  x = new_x;
  y = new_y;
}

void Turtle::penDown(){
  penIsDown = true;
}

void Turtle::penUp(){
  penIsDown = false;
}

void Turtle::clearScreen(uint16_t screen_color){
  tft->fillScreen(screen_color);
}
