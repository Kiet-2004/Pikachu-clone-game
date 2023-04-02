#include "lib.h"

//Clearing console screen
void ClearScreen();

//Changing the console size
void ResizeWindow(int posx, int posy, int width, int length);

//Setting color for console
void SetColor(WORD color);

//Hiding the blinking console cursor
void ShowConsoleCursor(bool showFlag);

//Move the cursor to 
void gotoxy(int x, int y);
