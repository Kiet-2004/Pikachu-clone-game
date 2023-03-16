#pragma once

void levelCheck(int m, int n, int **a, int x1, int y1, int x2, int y2, int lvl);
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