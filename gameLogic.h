#include "lib.h"

bool findPath(BoardState a, int x1, int x2, int y1, int y2, int line[][2]);
bool checkLegalMove(BoardState a);

/////////////////////////////////////////////////////////////////////////////////////////////

void levelCheck(BoardState a, int x1, int y1, int x2, int y2, int lvl, int lvlcap[]);
void goStand(BoardState a, int x1, int y1, int x2, int y2);
void goUp(BoardState a, int x1, int y1, int x2, int y2);
void goDown(BoardState a, int x1, int y1, int x2, int y2);
void goLeft(BoardState a, int x1, int y1, int x2, int y2);
void goRight(BoardState a, int x1, int y1, int x2, int y2);
void goSLR(BoardState a, int x1, int y1, int x2, int y2);
void goMLR(BoardState a, int x1, int y1, int x2, int y2);
void goSUD(BoardState a, int x1, int y1, int x2, int y2);
void goMUD(BoardState a, int x1, int y1, int x2, int y2);

/*
MLR = Merge Left-Right
MUD = Merge Up-Down
SLR = Split Left-Right
SUP = Split Up-Down
*/

/////////////////////////////////////////////////////////////////////////////////////////////////

void deleteNightmare(BoardState a, bool **&nightmare);
void generateNightmare(BoardState a, bool **&nightmare);
void resetNightmare(BoardState a, bool **nightmare);
