#include "gui.h"

void generateMenu(LeaderBoard lb, int &mode, int &row, int &col, int &menu, int &mCurX, bool &nmCheck, bool &succlog, bool &cont)
{
    printMenu(lb, row, col, menu, mCurX);
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
                    if (mCurX == 1 && row > 4)
                        row--;
                    else if (mCurX == 2 && col > 6)
                        col--;
                }
                break;
            }
            case KEY_RIGHT:
            {
                if (menu == 3)
                {
                    if (mCurX == 1 && row < 10)
                        row++;
                    else if (mCurX == 2 && col < 10)
                        col++;
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
                if(mode)
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
                        row = 4;
                        col = 6;
                        break;
                    }
                    case 2:
                    {
                        mode = 2;
                        row = 6;
                        col = 8;
                        break;
                    }
                    case 3:
                    {
                        mode = 3;
                        row = 10;
                        col = 10;
                        break;
                    }
                    case 4:
                    {
                        mode = 4;
                        row = 10;
                        col = 10;
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
            if (row * col % 2 == 0)
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
        row = 4;
        col = 6;
    }
}

void printMenu(LeaderBoard lb, int row, int col, int menu, int mCurX)
{
    cout << R"(                                  ,'\
    _.----.        ____         ,'  _\   ___    ___     ____
_,-'       `.     |    |  /`.   \,-'    |   \  /   |   |    \  |`.
\      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  |
 \.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  |
   \    \/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |
    \     ,-'/  /   \    ,'   | \/ / ,`.|         /  /   \  |     |
     \    \ |   \_/  |   `-.  \    `'  /|  |    ||   \_/  | |\    |
      \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   |
       \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   |
        \_.-'       |__|    `-._ |              '-.|     '-.| |   |
                                `'                            '-._|)" << endl;

    cout << endl << endl;

    switch (menu)
    {
        case 1:
        {
            if (mCurX == 1)
            {
                SetColor(3);
                cout << "\t\t\t\t ##################" << endl;
                cout << "\t\t\t\t #      START     #" << endl;
                cout << "\t\t\t\t ##################" << endl << endl;
                SetColor(6);
                cout << "\t\t\t\t ##################" << endl;
                cout << "\t\t\t\t #    CONTINUE    #" << endl;
                cout << "\t\t\t\t ##################" << endl << endl;
                cout << "\t\t\t\t ##################" << endl;
                cout << "\t\t\t\t #   LEADERBOARD  #" << endl;
                cout << "\t\t\t\t ##################" << endl << endl;
                cout << "\t\t\t\t ##################" << endl;
                cout << "\t\t\t\t #     LOG OUT    #" << endl;
                cout << "\t\t\t\t ##################" << endl << endl;
            }
            else if (mCurX == 2)
            {
                SetColor(6);
                cout << "\t\t\t\t ##################" << endl;
                cout << "\t\t\t\t #      START     #" << endl;
                cout << "\t\t\t\t ##################" << endl << endl;
                SetColor(3);
                cout << "\t\t\t\t ##################" << endl;
                cout << "\t\t\t\t #    CONTINUE    #" << endl;
                cout << "\t\t\t\t ##################" << endl << endl;
                SetColor(6);
                cout << "\t\t\t\t ##################" << endl;
                cout << "\t\t\t\t #   LEADERBOARD  #" << endl;
                cout << "\t\t\t\t ##################" << endl << endl;
                cout << "\t\t\t\t ##################" << endl;
                cout << "\t\t\t\t #     LOG OUT    #" << endl;
                cout << "\t\t\t\t ##################" << endl << endl;
            }
            else if (mCurX == 3)
            {
                SetColor(6);
                cout << "\t\t\t\t ##################" << endl;
                cout << "\t\t\t\t #      START     #" << endl;
                cout << "\t\t\t\t ##################" << endl << endl;
                cout << "\t\t\t\t ##################" << endl;
                cout << "\t\t\t\t #    CONTINUE    #" << endl;
                cout << "\t\t\t\t ##################" << endl << endl;
                SetColor(3);
                cout << "\t\t\t\t ##################" << endl;
                cout << "\t\t\t\t #   LEADERBOARD  #" << endl;
                cout << "\t\t\t\t ##################" << endl << endl;
                SetColor(6);
                cout << "\t\t\t\t ##################" << endl;
                cout << "\t\t\t\t #     LOG OUT    #" << endl;
                cout << "\t\t\t\t ##################" << endl << endl;
            }
            else if (mCurX == 4)
            {
                SetColor(6);
                cout << "\t\t\t\t ##################" << endl;
                cout << "\t\t\t\t #      START     #" << endl;
                cout << "\t\t\t\t ##################" << endl << endl;
                cout << "\t\t\t\t ##################" << endl;
                cout << "\t\t\t\t #    CONTINUE    #" << endl;
                cout << "\t\t\t\t ##################" << endl << endl;
                cout << "\t\t\t\t ##################" << endl;
                cout << "\t\t\t\t #   LEADERBOARD  #" << endl;
                cout << "\t\t\t\t ##################" << endl << endl;
                SetColor(3);
                cout << "\t\t\t\t ##################" << endl;
                cout << "\t\t\t\t #     LOG OUT    #" << endl;
                cout << "\t\t\t\t ##################" << endl << endl;
                SetColor(6);
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
                    cout << "Choose the number of rows:    < " << row << " >" << endl;
                    cout << "Choose the number of columns:   " << col << "  " << endl;
                    break;
                }
                case 2:
                {
                    cout << "Choose the number of rows:      " << row << "  " << endl;
                    cout << "Choose the number of columns: < " << col << " >" << endl;
                    break;
                }
            }
            break;
        }
        case 6:
        {
            cout << "\t  EASY  \t\t  MEDIUM  \t\t  HARD  \t\t  NIGHTMARE" << endl;
            for(int i = 0; i < 5; i++)
            {
                cout << "\t  " << lb.hsEasy[i] << "  " << lb.userEasy[i];
                cout << "\t\t  " << lb.hsMedium[i] << "  " << lb.userMedium[i];
                cout << "\t\t  " << lb.hsHard[i] << "  " << lb.userHard[i];
                cout << "\t\t  " << lb.hsNightmare[i] << "  " << lb.userNightmare[i];
                cout << endl;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////
void keyboardSelect(BoardState &a, int &curX, int &curY, int &x1, int &y1, int &x2, int &y2, int &menu, time_t &suggtime, time_t &timeleft){
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
        a.row = 4;
        a.col = 6;
    }
    else if (c == KEY_HELP)
    {
        suggtime = time(0);
        timeleft -= 5;
    }
}

void resetGame(BoardState a, int &count, int lvl, int lvlcap[], int &curX, int &curY)
{
    count = a.row * a.col;
    curX = 1;
    curY = 1;
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

void eraseGame(PlayerState &player, BoardState &a, int lvlcap[])
{
    a.row = 4;
    a.col = 6;
    player.mode = 0;
    player.lvl = 1;
    player.lvlstate = 1;
    player.count = 24;
    player.timeleft = 220;
    player.score = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
void showTime(int &timeleft, time_t oriTime, int &menu, bool &eot, int score, time_t &suggtime)
{
    time_t nowTime = time(0);
    timeleft = 220 - (difftime(nowTime, oriTime));
    if (timeleft < 0)
        endGame(menu, eot, score);
    if (suggtime)
        if(difftime(nowTime, suggtime) >= 5)
            suggtime = 0;
    cout << endl << "Time left: " << timeleft;
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
  PlaySound(TEXT("others\\music_1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
