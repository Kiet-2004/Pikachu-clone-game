#pragma once
#include <windows.h>
#include <conio.h>
#include <bits/stdc++.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32
#define KEY_ESCAPE 27
#define cursor(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x, y})

void generateMenu(int &m, int &n, int &mSelect, int &mCurX, int &mCurY, bool &nmCheck);
void printMenu(int m, int n, int mSelect, int mCurX, int mCurY);
