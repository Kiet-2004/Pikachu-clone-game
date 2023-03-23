#ifndef _LIB_H
#define _LIB_H
#include <bits/stdc++.h>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <conio.h>

using namespace std;

struct BoardState{
    int **board;
    char **display;
    int col, row;
};

struct PlayerState{
    int highscore;
    int currentLvl;
    int currentMode;
    char username[30];
    char password[30];
};

struct SaveState{
    BoardState save;
    PlayerState info;
};

#endif