#include "lib.h"

void deleteMem(BoardState &a);
void generateBoard(BoardState &a);
void showBoard(BoardState a, int curX, int curY, int x, int y, bool **nightmare, bool nmCheck, time_t suggtime, int sugx1, int sugy1, int sugx2, int sugy2);
void resetBoard(BoardState a);
