#include "lib.h"

bool findPath(BoardState a, int x1, int x2, int y1, int y2, int line[][2]);
bool checkLegalMove(BoardState a, int &sugx1, int &sugy1, int &sugx2, int &sugy2);

/////////////////////////////////////////////////////////////////////////////////////////////

void levelCheck(BoardState a, int x1, int y1, int x2, int y2, int lvl, int lvlcap[]);
void goUp(BoardState a, int x, int y, int m);
void goDown(BoardState a, int x, int y, int m);
void goLeft(BoardState a, int x, int y, int n);
void goRight(BoardState a, int x, int y, int n);

/////////////////////////////////////////////////////////////////////////////////////////////////

void deleteNightmare(BoardState a, bool **&nightmare);
void generateNightmare(BoardState a, bool **&nightmare);
void resetNightmare(BoardState a, bool **nightmare);

/////////////////////////////////////////////////////////////////////////////////////////////////

void calculateScore(PlayerState &player);
