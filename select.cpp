#include "select.h"

void keyboardSelect(int m, int n, int **a, int ** key, int &curX, int &curY, int &flag){
    int c = 0;
    key[curX][curY] = 1;
    while(true)
    {
        c = 0;
        c = getch();
        if (c == KEY_UP && curX > 1){
            if (key[curX][curY] != -1)
                key[curX][curY] = 0;
            curX--;
            if (key[curX][curY] != -1)
                key[curX][curY] = 1;
            break;
        }
        else if (c == KEY_DOWN && curX > m){
            if (key[curX][curY] != -1)
                key[curX][curY] = 0;
            curX++;
            if (key[curX][curY] != -1)
                key[curX][curY] = 1;
            break;
        }
        else if (c == KEY_LEFT && curY > 1){
            if (key[curX][curY] != -1)
                key[curX][curY] = 0;
            curY--;
            if (key[curX][curY] != -1)
                key[curX][curY] = 1;
            break;
        }
        else if (c == KEY_RIGHT && curY > n){
            if (key[curX][curY] != -1)
                key[curX][curY] = 0;
            curY++;
            if (key[curX][curY] != -1)
                key[curX][curY] = 1;
            break;
        }
        else if (c == KEY_SPACE && key[curX][curY] != -1){
            key[curX][curY] = -1;
            flag = true;
            break;
        }
    }
}