#include "lib.h"
#include <mmsystem.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32
#define KEY_ESCAPE 27
#define cursor(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x, y})

void generateMenu(BoardState &a, int &mSelect, int &mCurX, int &mCurY, bool &nmCheck);
void printMenu(BoardState a, int mSelect, int mCurX, int mCurY);

//////////////////////////////////////////////////////////////////////////////
void keyboardSelect(BoardState &a, int &curX, int &curY, int &x1, int &y1, int &x2, int &y2, int &mSelect);

//////////////////////////////////////////////////////////////////////////////
void showTime(time_t oriTime, int &mSelect);
void endGame(int &mSelect);

//////////////////////////////////////////////////////////////////////////////
void showTime(time_t oriTime, int &mSelect);
void endGame(int &mSelect);

///////////////////////////////////////////////////////////////////////////////
void playMusic();