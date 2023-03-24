#include "gui.h"

void generateMenu(PlayerState player, BoardState &a, int &menu, int &mCurX, bool &nmCheck, int &mode, bool &succlog, SaveState save, bool &cont)
{
    printMenu(player, a, menu, mCurX);
    int c = getch(), ch;
    if(c == 224)
        switch(ch = getch())
        {
            case KEY_UP:
            {
                if(mCurX > 1)
                    mCurX--;
                else if (menu == 1)
                    mCurX = 4;
                else if (menu == 2)
                    mCurX = 5;
                else if (menu == 3)
                    mCurX = 2;
                break;
            }
            case KEY_DOWN:
            {
                if((menu == 1 && mCurX < 4) || (menu == 2 && mCurX < 5) || (menu == 3 && mCurX < 2))
                    mCurX++;
                else
                    mCurX = 1;
                break;
            }
            case KEY_LEFT:
            {
                if (menu == 3)
                {
                    if (mCurX == 1 && a.row > 4)
                        a.row--;
                    else if (mCurX == 2 && a.col > 6)
                        a.col--;
                }
                break;
            }
            case KEY_RIGHT:
            {
                if (menu == 3)
                {
                    if (mCurX == 1 && a.row < 10)
                        a.row++;
                    else if (mCurX == 2 && a.col < 10)
                        a.col++;
                }
                break;
            }
        }
    else if (c == KEY_SPACE)
    {
        if (menu == 1)
        {
            if (mCurX == 1)
                menu++;
            else if (mCurX == 2)
            {
                if(save.mode)
                {
                    cont = true;
                    mCurX = 1;
                    menu = 4;
                }
            }
            else if (mCurX == 3)
            {
                mCurX = 1;
                menu = 6;
            }
            else if (mCurX == 4)
            {
                succlog = false;
                mCurX = 1;
            }
        }
        else if (menu == 2)
        {
            if (mCurX == 5)
                menu = 3;
            else
            {
                switch (mCurX)
                {
                    case 1:
                    {
                        mode = 1;
                        a.row = 4;
                        a.col = 6;
                        break;
                    }
                    case 2:
                    {
                        mode = 2;
                        a.row = 6;
                        a.col = 8;
                        break;
                    }
                    case 3:
                    {
                        mode = 3;
                        a.row = 10;
                        a.col = 10;
                        break;
                    }
                    case 4:
                    {
                        a.row = 10;
                        a.col = 10;
                        nmCheck = true;
                        break;
                    }
                }
                menu = 4;
            }
            mCurX = 1;
        }
        else if (menu == 3)
        {
            if (a.row * a.col % 2 == 0)
            {
                mCurX = 1;
                menu = 4;
            }
        }
    }
    else if (c == KEY_ESCAPE)
    {
        menu = 1;
        mCurX = 1;
        a.row = 4;
        a.col = 6;
    }
}

void printMenu(PlayerState player, BoardState a, int menu, int mCurX)
{
    cout << endl << "\t\tPikachuchu" << endl << endl;
    switch (menu)
    {
        case 1:
        {
            if (mCurX == 1)
            {
                cout << "\t\t< START >" << endl;
                cout << "\t\t  CONTINUE" << endl;
                cout << "\t\t  LEADERBOARD" << endl;
                cout << "\t\t  LOG OUT" << endl;
            }
            else if (mCurX == 2)
            {
                cout << "\t\t  START" << endl;
                cout << "\t\t< CONTINUE >" << endl;
                cout << "\t\t  LEADERBOARD" << endl;
                cout << "\t\t  LOG OUT" << endl;
            }
            else if (mCurX == 3)
            {
                cout << "\t\t  START" << endl;
                cout << "\t\t  CONTINUE" << endl;
                cout << "\t\t< LEADERBOARD >" << endl;
                cout << "\t\t  LOG OUT" << endl;
            }
            else if (mCurX == 4)
            {
                cout << "\t\t  START" << endl;
                cout << "\t\t  CONTINUE" << endl;
                cout << "\t\t  LEADERBOARD" << endl;
                cout << "\t\t< LOG OUT >" << endl;
            }
            break;
        }
        case 2:
        {
            switch (mCurX)
            {
                case 1:
                {
                    cout << "\t\t< Easy >" << endl;
                    cout << "\t\t  Medium" << endl;
                    cout << "\t\t  Hard" << endl;
                    cout << "\t\t  Nightmare" << endl;
                    cout << "\t\t  Custom" << endl;
                    break;
                }
                case 2:
                {
                    cout << "\t\t  Easy" << endl;
                    cout << "\t\t< Medium >" << endl;
                    cout << "\t\t  Hard" << endl;
                    cout << "\t\t  Nightmare" << endl;
                    cout << "\t\t  Custom" << endl;
                    break;
                }
                case 3:
                {
                    cout << "\t\t  Easy" << endl;
                    cout << "\t\t  Medium" << endl;
                    cout << "\t\t< Hard >" << endl;
                    cout << "\t\t  Nightmare" << endl;
                    cout << "\t\t  Custom" << endl;
                    break;
                }
                case 4:
                {
                    cout << "\t\t  Easy" << endl;
                    cout << "\t\t  Medium" << endl;
                    cout << "\t\t  Hard" << endl;
                    cout << "\t\t< Nightmare >" << endl;
                    cout << "\t\t  Custom" << endl;
                    break;
                }
                case 5:
                {
                    cout << "\t\t  Easy" << endl;
                    cout << "\t\t  Medium" << endl;
                    cout << "\t\t  Hard" << endl;
                    cout << "\t\t  Nightmare" << endl;
                    cout << "\t\t< Custom >" << endl;
                    break;
                }
            }
            break;
        }
        case 3:
        {
            switch (mCurX)
            {
                case 1:
                {
                    cout << "Choose the number of rows:    < " << a.row << " >" << endl;
                    cout << "Choose the number of columns:   " << a.col << "  " << endl;
                    break;
                }
                case 2:
                {
                    cout << "Choose the number of rows:      " << a.row << "  " << endl;
                    cout << "Choose the number of columns: < " << a.col << " >" << endl;
                    break;
                }
            }
        }
        case 6:
        {
            cout << "\t  EASY  \t\t  MEDIUM  \t\t  HARD  \t\t  NIGHTMARE" << endl;
            for(int i = 0; i < 5; i++)
            {
                cout << "\t  " << player.hsEasy[i];
                cout << "\t\t\t  " << player.hsMedium[i];
                cout << "\t\t\t  " << player.hsHard[i];
                cout << "\t\t\t  " << player.hsNightmare[i];
                cout << endl;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////
void keyboardSelect(BoardState &a, int &curX, int &curY, int &x1, int &y1, int &x2, int &y2, int &menu){
    int c = getch(), ch;
    if(c == 224)
        switch(ch = getch())
        {
            case KEY_UP:
            {
                if(curX > 1)
                    curX--;
                else
                    curX = a.row;
                break;
            }
            case KEY_DOWN:
            {
                if(curX < a.row)
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
                    curY = a.col;
                break;
            }
            case KEY_RIGHT:
            {
                if(curY < a.col)
                    curY++;
                else
                    curY = 1;
                break;
            }
        }
    else if (c == KEY_SPACE)
    {
        if(a.board[curX][curY])
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
    else if (c == KEY_ESCAPE)
    {
        menu = 1;
    }
}

void resetGame(BoardState a, int &count, int lvl, int lvlcap[],int &curX, int &curY)
{
    count = a.row * a.col;
    curX = 1;
    curY = 1;
    lvlcap[0] = 1;
    while(lvl - (9 - lvlcap[8]) > 0)
    {
        lvl -= (9 - lvlcap[8]);
        for(int i = 8; i >= 1; i--)
        {
            if (lvlcap[i] != i)
            {
                lvlcap[i]++;
                for(int u = i + 1; u < 9; u++)
                    lvlcap[u] = lvlcap[u - 1] + 1;
                break;
            }
        }
    }
    lvlcap[9] = lvl + lvlcap[8];
}

//////////////////////////////////////////////////////////////////////////////////////////////////
void showTime(time_t oriTime, int &menu, bool &eot, int score)
{
    time_t nowTime = time(0);
    int diff = difftime(nowTime, oriTime);
    if (220 - diff < 0)
        endGame(menu, eot, score);
    cout << endl << "Time left: ";
    for (int i = 220 - diff; i > 0; i--)
        cout << "|";
    for (int i = diff; i > 0; i--)
        cout << " ";
}

void endGame(int &menu, bool &eot, int score)
{
    cout << endl << endl << "Time end!";
    cout << endl << "Your score: " << score << endl;
    getch();
    menu = 1;
    eot = true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
 void playMusic()
 {
     PlaySound(TEXT("music_1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
 }
