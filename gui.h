#include "lib.h"

void generateMenu(PlayerState player, BoardState &a, int &menu, int &mCurX, bool &nmCheck, int &mode, bool &succlog, SaveState save, bool &cont);
void printMenu(PlayerState player, BoardState a, int menu, int mCurX);

/*
 menu = 1: main menu
        2: choose gamemode
        3: custom gamemode
        4, 5: in gameplay
        6: leaderboard
        0: out
*/

//////////////////////////////////////////////////////////////////////////////
void keyboardSelect(BoardState &a, int &curX, int &curY, int &x1, int &y1, int &x2, int &y2, int &menu);
void resetGame(BoardState a, int &count, int lvl, int lvlcap[],int &curX, int &curY);

//////////////////////////////////////////////////////////////////////////////
void showTime(time_t oriTime, int &menu, bool &eot, int score);
void endGame(int &menu, bool &eot, int score);

///////////////////////////////////////////////////////////////////////////////
void playMusic();
