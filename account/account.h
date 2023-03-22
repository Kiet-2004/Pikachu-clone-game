#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Player{
    int currentGamemode = 1; 
    int currentLvl = 1;  
    int highscore = 1;  
    char username[30] = "";
    char password[30] = "";
};

void readData(vector<Player> &list);
void writeData(vector<Player> &list);
void login(vector<Player> &list, Player &a, bool &flag);
void signUp(vector<Player> &list, Player &a, bool &flag);