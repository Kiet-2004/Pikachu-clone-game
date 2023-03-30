#include "lib.h"
#include "consoleSetting.cpp"

void deleteMem(BoardState &a);
void generateBoard(BoardState &a);
void showBoard(BoardState a, int curX, int curY, int &FcurX, int &FcurY, int &x1, int &y1, int &x2, int &y2, bool nmCheck, bool **nightmare, time_t suggtime, bool &endsugg, int sugx1, int sugy1, int sugx2, int sugy2, bool &newgame, bool &return0, int line[][2]);
void resetBoard(BoardState a);

void generateArt(BoardState &a);
void deleteArt(BoardState &a);
void drawLine(int line[][2]);
