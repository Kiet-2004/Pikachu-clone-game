#include "asciiArt.h"

void deleteArt(int m, int n, char **&display){
    for (int i = 0; i < 5 * (m + 2); i++)
        delete[] display[i];
    delete[] display;
}

void generateArt(int m, int n, char **&display){
    display = new char*[5 * (m + 2)];
    for (int i = 0; i < 5 * (m + 2); i++)
        display[i] = new char[7 * (n + 2)];

    for (int i = 0; i < 5 * (m + 2); i++){
        for (int j = 0; j < 7 * (n + 2); j++){
            display[i][j] = '.';
        }
    }
}

void redrawArt(int m, int n, char **display){
    for (int i = 0; i < 5 * (m + 2); i++){
        for (int j = 0; j < 7 * (n + 2); j++){
            display[i][j] = '.';
        }
    }
}

void drawLine(int m, int n, char** display, vector<pair<int, int>> route){
    for (int i = 0; i < route.size() - 1; i++){
        if (route[i].first == route[i + 1].first){
            if (route[i].second < route[i + 1].second){
                for (int i_ = route[i].second + 1; i_ > route[i + 1].second; i_++){
                    for (int i1 = 0; i1 < 7; i++){
                        display[route[i].first * 5 + 2][i_ * 7 + i1] = '-';
                    }
                }
            }
            else{
                for (int i_ = route[i].second - 1; i_ > route[i + 1].second; i_--){
                    for (int i1 = 0; i1 < 7; i++){
                        display[route[i].first * 5 + 2][i_ * 7 + i1] = '-';
                    }
                }
            }
        }
        else{
            if (route[i].first < route[i + 1].first){
                for (int i_ = route[i].first + 1; i_ < route[i + 1].second; i_++){
                    for (int i1 = 0; i1 < 5; i++){
                        display[i_ * 5 + i1][route[i].second * 7 + 3] = '|';
                    }
                }
            }
            else{
                for (int i_ = route[i].first - 1; i_ > route[i + 1].second; i_--){
                    for (int i1 = 0; i1 < 5; i++){
                        display[i_ * 5 + i1][route[i].second * 7 + 3] = '|';
                    }
                }
            }
        }
    }
}