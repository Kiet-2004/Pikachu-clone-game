#pragma once
#include <bits/stdc++.h>
using namespace std;

void deleteMem(int m, int n, int **&a);
void generateBoard(int &m, int &n, int **&a, bool newgame);
void showBoard(int m, int n, int **a, int curX, int curY, int x, int y, char **display);
void resetBoard(int m, int n, int **a);