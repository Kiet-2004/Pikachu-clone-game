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
#define KEY_ENTER 13
#define KEY_SPACE 32
#define KEY_ESCAPE 27
#define KEY_HELP 104
#define cursor(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x, y})

struct BoardState{
    int row = 4, col = 6;
    int **board;
    char **display;
};

struct PlayerState{
    char username[32] = "";
    char password[32] = "";
    int mode = 0;
    int lvl = 1;
    int lvlstate = 1;
    int count = 24;
    int timeleft = 220;
    int score = 0;
};

struct LeaderBoard{
    int hsEasy[5] = {};
    char userEasy[5][32] = {};
    int hsMedium[5] = {};
    char userMedium[5][32] = {};
    int hsHard[5] = {};
    char userHard[5][32] = {};
    int hsNightmare[5] = {};
    char userNightmare[5][32] = {};
};

#endif
