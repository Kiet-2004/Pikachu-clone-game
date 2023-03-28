#include "lib.h"
#include "consoleSetting.cpp"

void generateMenu(LeaderBoard lb, int &mode, int &row, int &col, int &menu, int &mCurX, bool &nmCheck, bool &succlog, bool &cont);
void printMenu(LeaderBoard lb, int row, int col, int menu, int mCurX);

/*
 menu = 1: main menu
        2: choose gamemode
        3: custom gamemode
        4, 5: in gameplay
        6: leaderboard
        0: out
*/

//////////////////////////////////////////////////////////////////////////////
void keyboardSelect(BoardState &a, int &curX, int &curY, int &x1, int &y1, int &x2, int &y2, int &menu, time_t &suggtime, time_t &timeleft);
void resetGame(BoardState a, int &count, int lvl, int lvlcap[],int &curX, int &curY);
void eraseGame(PlayerState &player, BoardState &a, int lvlcap[]);

//////////////////////////////////////////////////////////////////////////////
void showTime(int &timeleft, time_t oriTime, int &menu, bool &eot, int score, time_t &suggtime, BoardState a);
void endGame(int &menu, bool &eot, int score, BoardState a);

///////////////////////////////////////////////////////////////////////////////
void playMusic();
