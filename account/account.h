#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Player{
    char username[30] = "";
    char password[30] = "";
    int highscore = 0;
};

struct Save{
    char username[30] = "";
    int currentGamemode = 1; 
    int currentLvl = 1;  
    int timeLeft = 1;  
    int row, col;
    int **board;
};

void readData(vector<Player> &list);
void writeData(vector<Player> &list);
void login(vector<Player> &list, Player &a, bool &flag);
void signUp(vector<Player> &list, Player &a, bool &flag);

void readSaveFile(vector<Save> &a);
void writeSaveFile(vector<Save> &a);