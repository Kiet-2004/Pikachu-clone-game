#pragma once
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void generateArt(int m, int n, char **&display);
void drawLine(int m, int n, char** display, vector<pair<int, int>> route);
void deleteArt(int m, int n, char **&display);
void redrawArt(int m, int n, char **display);