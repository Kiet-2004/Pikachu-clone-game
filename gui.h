#include "lib.h"

void generateMenu(BoardState &a, int &menu, int &mCurX, bool &nmCheck);
void printMenu(BoardState a, int menu, int mCurX);

/*
 menu = 1: main menu
        2: choose gamemode
        3: custom gamemode
        4: in gameplay
        0: out
*/

//////////////////////////////////////////////////////////////////////////////
void keyboardSelect(BoardState &a, int &curX, int &curY, int &x1, int &y1, int &x2, int &y2, int &menu);
void resetGame(BoardState a, int &count, int lvl, int lvlcap[],int &curX, int &curY);

//////////////////////////////////////////////////////////////////////////////
void showTime(time_t oriTime, int &menu);
void endGame(int &menu);

///////////////////////////////////////////////////////////////////////////////
void playMusic();
