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
            display[i][j] = '~';
        }
    }
}