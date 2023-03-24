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
    int **board;
    char **display;
    int col, row;
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
    BoardState save;
    int lvlState[2];
    time_t savetime;
    string username;
};

#endif
