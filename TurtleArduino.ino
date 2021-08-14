#include "Color.h"
#include "Turtle.h"
#include <Elegoo_TFTLCD.h>
#include <Elegoo_GFX.h>
#define PHI 1.6180339887

Elegoo_TFTLCD tft(A3, A2, A1, A0, A4);
Turtle turtle(0,0,0, &tft);

void setup() {
  Serial.begin(9600);
  tft.reset();
  tft.begin(0x9341);
  tft.fillScreen(BLACK);

  /*POLYGON
  turtle.teleport(70,10);
  drawPolygon(&turtle, 3, 50);
  turtle.teleport(170,10);
  drawPolygon(&turtle, 4, 40);
  turtle.teleport(70,100);
  drawPolygon(&turtle, 5, 35);
  turtle.teleport(170,100);
  drawPolygon(&turtle, 6, 30);
  turtle.teleport(70,200);
  drawPolygon(&turtle, 7, 25);
  turtle.teleport(170,200);
  drawPolygon(&turtle, 8, 20);
  */  


  /* CIRCLE
  for(int i = 10; i < 200; i+=5){
    turtle.teleport(70,10);
    drawCircle(&turtle, i);
  }
  */

  /* TREE
  turtle.teleport(0,round(tft.height()/2.));
  drawRecTree(&turtle,10, 200, 55);
  */
  
  /* KOSH
  for(int i = 1; i < 6; i++){
      drawKosh(&turtle, 300, i);
      delay(1000);
  }
  */
}

void loop() {

}

void goToCenter(Turtle * turtle){
  turtle->teleport(round(tft.width()/2.),round(tft.height()/2.));
  
}

void drawPolygon(Turtle * turtle,int n, double l){
  for(int i = 1; i <= n; i++){
    turtle->turnRight(360.0/n);
    turtle->moveForward(l);
  }
}

void drawCircle(Turtle *turtle, double radius){
  int n = 500;
  double l = (2*PI*radius)/n;
  drawPolygon(turtle, n,l);
}

void drawRecTree(Turtle * turtle, int nbRec, double l, double angle){
  if(nbRec <= 1){
    return;
  }
  turtle->moveForward(l/2);
  turtle->turnLeft(angle/2);
  drawRecTree(turtle, nbRec-1, l/2, angle);
  turtle->turnRight(angle);
  drawRecTree(turtle, nbRec-1, l/2, angle);
  turtle->turnLeft(angle/2);
  turtle->moveBackward(l/2);
}


void drawKosh(Turtle *turtle, double l, int iter){
  tft.fillScreen(BLACK);
  turtle->setColor(WHITE);
  turtle->teleport(10,10);
  turtle->setRotation(90);
  _drawKosh(turtle, l, iter);
}

void _drawKosh(Turtle *turtle, double l, int iter){
  if(iter == 0){
    turtle->moveForward(l);
  } else {
    _drawKosh(turtle, l/3, iter-1);
    turtle->turnLeft(60);
    _drawKosh(turtle, l/3, iter-1);
    turtle->turnRight(120);
    _drawKosh(turtle, l/3, iter-1);
    turtle->turnLeft(60);
    _drawKosh(turtle, l/3, iter-1);
  }
}
