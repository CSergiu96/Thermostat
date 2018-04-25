#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

#define rs PB0    //pin8
#define en PB1 //pin9

void start();
void command(char);
void data(char);
void Send_A_String(char *StringOfCharacters);
void cut(char *str);
void Send_An_Integer(int x);
void setCursor(int row,int column);
void clearScreen();
void home();
void cursor();
void noCursor();
void blink();
void noBlink();
void display();
void noDisplay();
void scrollDisplayLeft();
void scrollDisplayRight();
void autoscroll();
void noAutoscroll();
void createChar(int num,unsigned int *charArray);