#pragma once
#include "lib.h"
#define cursor(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x, y})

void generateArt(int m, int n, char **&display);
void deleteArt(int m, int n, char **&display);
void drawLine(int line[][2]);
