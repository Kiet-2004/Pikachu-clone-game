#include "lib.h"
#include "consoleSetting.cpp"

void deleteMem(BoardState &a);
void generateBoard(BoardState &a);
void printCell(int color, int data, int x, int y, bool nmCheck, bool **nightmare);
void clearCell(BoardState a, int x, int y);
void printCursor(BoardState a, int x, int y, bool nmCheck, bool **nightmare);
void showBoard(BoardState a, int lvl, int curX, int curY, int &FcurX, int &FcurY, int &x1, int &y1, int &x2, int &y2, bool nmCheck, bool **nightmare, time_t suggtime, bool &endsugg, int sugx1, int sugy1, int sugx2, int sugy2, bool &newgame, bool &hint, bool &choose_1, bool &choose_2);
void resetBoard(BoardState a);

void generateArt(BoardState &a);
void deleteArt(BoardState &a);
void drawLine(int line[][2]);
void clearLine(int line[][2], BoardState a);
