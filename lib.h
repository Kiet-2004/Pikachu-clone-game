#ifndef _LIB_H
#define _LIB_H
#include <bits/stdc++.h>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <mmsystem.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32
#define KEY_ESCAPE 27
#define cursor(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x, y})

struct BoardState{
    int col, row;
    int **board;
    char **display;
};

struct PlayerState{
    char username[32] = "";
    char password[32] = "";
    int hsEasy[5] = {};
    int hsMedium[5] = {};
    int hsHard[5] = {};
    int hsNightmare[5] = {};
};

struct SaveState{
    int lvlState[2] = {1, 1};
    int row = 4;
    int col = 6;
    int board[100] = {};
    int count = 0;
    int mode = 0;
    time_t time = 220;
    int score = 0;
};

#endif
