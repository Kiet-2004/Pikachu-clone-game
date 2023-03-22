#pragma once
#include "lib.h"

bool findPath(int m, int n, int **a, int x1, int x2, int y1, int y2, int line[][2]);
bool checkLegalMove(int m, int n, int **a);

/////////////////////////////////////////////////////////////////////////////////////////////

void levelCheck(int m, int n, int **a, int x1, int y1, int x2, int y2, int lvl, int lvlcap[]);
void goStand(int m, int n, int **a, int x1, int y1, int x2, int y2);
void goUp(int m, int n, int **a, int x1, int y1, int x2, int y2);
void goDown(int m, int n, int **a, int x1, int y1, int x2, int y2);
void goLeft(int m, int n, int **a, int x1, int y1, int x2, int y2);
void goRight(int m, int n, int **a, int x1, int y1, int x2, int y2);
void goSLR(int m, int n, int **a, int x1, int y1, int x2, int y2);
void goMLR(int m, int n, int **a, int x1, int y1, int x2, int y2);
void goSUD(int m, int n, int **a, int x1, int y1, int x2, int y2);
void goMUD(int m, int n, int **a, int x1, int y1, int x2, int y2);

/*
MLR = Merge Left-Right
MUD = Merge Up-Down
SLR = Split Left-Right
SUP = Split Up-Down
*/

/////////////////////////////////////////////////////////////////////////////////////////////////

void deleteNightmare(int m, int n, bool **&nightmare);
void generateNightmare(int m, int n, bool **&nightmare);
void resetNightmare(int m, int n, bool **nightmare);
