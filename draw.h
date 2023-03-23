#include "lib.h"
#define cursor(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x, y})

void generateArt(BoardState &a);
void deleteArt(BoardState &a);
void drawLine(int line[][2]);
