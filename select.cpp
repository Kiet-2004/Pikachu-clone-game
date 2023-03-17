#include "select.h"

void keyboardSelect(int m, int n, int **a, int &curX, int &curY, int &x1, int &y1, int &x2, int &y2){
    int c = getch(), ch;
    if(c == 224)
        switch(ch = getch())
        {
            case KEY_UP:
            {
                if(curX > 1)
                    curX--;
                else
                    curX = m;
                break;
            }
            case KEY_DOWN:
            {
                if(curX < m)
                    curX++;
                else
                    curX = 1;
                break;
            }
            case KEY_LEFT:
            {
                if(curY > 1)
                    curY--;
                else
                    curY = n;
                break;
            }
            case KEY_RIGHT:
            {
                if(curY < n)
                    curY++;
                else
                    curY = 1;
                break;
            }
        }
    else if (c == KEY_SPACE)
    {
        if(a[curX][curY])
        {
            if (x1)
            {
                if (curX != x1 || curY != y1)
                {
                    x2 = curX;
                    y2 = curY;
                }
                else
                {
                    x1 = 0;
                    y1 = 0;
                }
            }
            else
            {
                x1 = curX;
                y1 = curY;
            }
        }
        else
        {
            x1 = 0;
            y1 = 0;
        }
    }
}
