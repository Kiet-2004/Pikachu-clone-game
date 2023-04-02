#include "gui.h"

void generateMenu(LeaderBoard lb, int &mode, int &row, int &col, int &menu, int &mCurX, bool &nmCheck, bool &succlog, bool &cont, int &lvl)
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
    else if (c == KEY_SPACE || c == KEY_ENTER)
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
                        lvl = 1;
                        mode = 1;
                        row = 4;
                        col = 6;
                        break;
                    }
                    case 2:
                    {
                        lvl = 1;
                        mode = 2;
                        row = 6;
                        col = 8;
                        break;
                    }
                    case 3:
                    {
                        lvl = 1;
                        mode = 3;
                        row = 10;
                        col = 10;
                        break;
                    }
                    case 4:
                    {
                        lvl = 1;
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
    SetColor(6);
    cout << "\t\t" << R"(                                  ,'\)" << endl
         << "\t\t" << R"(    _.----.        ____         ,'  _\   ___    ___     ____)" << endl
         << "\t\t" << R"(_,-'       `.     |    |  /`.   \,-'    |   \  /   |   |    \  |`.)" << endl
         << "\t\t" << R"(\      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  |)" << endl
         << "\t\t" << R"( \.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  |)" << endl
         << "\t\t" << R"(   \    \/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |)" << endl
         << "\t\t" << R"(    \     ,-'/  /   \    ,'   | \/ / ,`.|         /  /   \  |     |)" << endl
         << "\t\t" << R"(     \    \ |   \_/  |   `-.  \    `'  /|  |    ||   \_/  | |\    |)" << endl
         << "\t\t" << R"(      \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   |)" << endl
         << "\t\t" << R"(       \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   |)" << endl
         << "\t\t" << R"(        \_.-'       |__|    `-._ |              '-.|     '-.| |   |)" << endl
         << "\t\t" << R"(                                `'                            '-._|)" << endl;

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
                    SetColor(3);
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #      EASY      #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    SetColor(6);
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #     MEDIUM     #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #      HARD      #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #    NIGHTMARE   #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #     CUSTOM     #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    break;
                }
                case 2:
                {
                    SetColor(6);
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #      EASY      #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    SetColor(3);
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #     MEDIUM     #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    SetColor(6);
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #      HARD      #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #    NIGHTMARE   #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #     CUSTOM     #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    break;
                }
                case 3:
                {
                    SetColor(6);
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #      EASY      #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #     MEDIUM     #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    SetColor(3);
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #      HARD      #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    SetColor(6);
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #    NIGHTMARE   #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #     CUSTOM     #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    break;
                }
                case 4:
                {
                    SetColor(6);
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #      EASY      #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #     MEDIUM     #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #      HARD      #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    SetColor(3);
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #    NIGHTMARE   #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    SetColor(6);
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #     CUSTOM     #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    break;
                }
                case 5:
                {
                    SetColor(6);
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #      EASY      #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #     MEDIUM     #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #      HARD      #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #    NIGHTMARE   #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    SetColor(3);
                    cout << "\t\t\t\t ##################" << endl;
                    cout << "\t\t\t\t #     CUSTOM     #" << endl;
                    cout << "\t\t\t\t ##################" << endl << endl;
                    SetColor(6);
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
                    SetColor(3);
                    gotoxy(15, 32);
                    cout << "##############################################";
                    gotoxy(16, 32);
                    cout << "# Choose the number of rows:       <  " << setw(2) << setfill(' ') << row << "  >  #";
                    gotoxy(17, 32);
                    cout << "##############################################";
                    SetColor(6);
                    gotoxy(19, 32);
                    cout << "##############################################";
                    gotoxy(20, 32);
                    cout << "# Choose the number of columns:       " << setw(2) << setfill(' ') << col << "     #";
                    gotoxy(21, 32);
                    cout << "##############################################";
                    break;
                }
                case 2:
                {
                    SetColor(6);
                    gotoxy(15, 30);
                    cout << "##############################################";
                    gotoxy(16, 30);
                    cout << "# Choose the number of rows:          " << setw(2) << setfill(' ') << row << "     #";
                    gotoxy(17, 30);
                    cout << "##############################################";
                    SetColor(3);
                    gotoxy(19, 30);
                    cout << "##############################################";
                    gotoxy(20, 30);
                    cout << "# Choose the number of columns:    <  " << setw(2) << setfill(' ') << col << "  >  #";
                    gotoxy(21, 30);
                    cout << "##############################################";
                    SetColor(6);
                    break;
                }
            }
            break;
        }
        case 6:
        {
            SetColor(2);
            gotoxy(15, 8);
            cout << "##########################################";
            gotoxy(16, 8);
            cout << "#                  EASY                  #";
            gotoxy(17, 8);
            cout << "##########################################";
            for (int i = 0; i < 5; i++){
                gotoxy(18 + i, 8);
                cout << "# " << setw(5) << setfill(' ') << lb.hsEasy[i] << " - " << setw(30) << setfill(' ') << lb.userEasy[i] << " #";
            }
            gotoxy(23, 8);
            cout << "##########################################";

            SetColor(3);
            gotoxy(15, 53);
            cout << "##########################################";
            gotoxy(16, 53);
            cout << "#                 MEDIUM                 #";
            gotoxy(17, 53);
            cout << "##########################################";
            for (int i = 0; i < 5; i++){
                gotoxy(18 + i, 53);
                cout << "# " << setw(5) << setfill(' ') << lb.hsMedium[i] << " - " << setw(30) << setfill(' ') << lb.userMedium[i] << " #";
            }
            gotoxy(23, 53);
            cout << "##########################################";

            SetColor(4);
            gotoxy(25, 8);
            cout << "##########################################";
            gotoxy(26, 8);
            cout << "#                  HARD                  #";
            gotoxy(27, 8);
            cout << "##########################################";
            for (int i = 0; i < 5; i++){
                gotoxy(28 + i, 8);
                cout << "# " << setw(5) << setfill(' ') << lb.hsHard[i] << " - " << setw(30) << setfill(' ') << lb.userHard[i] << " #";
            }
            gotoxy(33, 8);
            cout << "##########################################";

            SetColor(5);
            gotoxy(25, 53);
            cout << "##########################################";
            gotoxy(26, 53);
            cout << "#                NIGHTMARE               #";
            gotoxy(27, 53);
            cout << "##########################################";
            for (int i = 0; i < 5; i++){
                gotoxy(28 + i, 53);
                cout << "# " << setw(5) << setfill(' ') << lb.hsNightmare[i] << " - " << setw(30) << setfill(' ') << lb.userNightmare[i] << " #";
            }
            gotoxy(33, 53);
            cout << "##########################################";

        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////
void keyboardSelect(BoardState &a, int &curX, int &curY, int &x1, int &y1, int &x2, int &y2, int &menu, time_t &suggtime, time_t &timeleft, bool &hint, bool &choose_1, bool &choose_2){
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
    else if (c == KEY_SPACE || c == KEY_ENTER){
        if (x1){
            choose_2 = true;
            x2 = curX;
            y2 = curY;
        }
        else if(a.board[curX][curY]){
            choose_1 = true;
            x1 = curX;
            y1 = curY;
        }
    }
    else if (c == KEY_ESCAPE)
        menu = 1;
    else if (c == KEY_HELP){
        hint = true;
        suggtime = time(0);
        timeleft -= 5;
    }
}

void resetGame(BoardState a, int &count, int lvl, int lvlcap[], int &curX, int &curY, int &FcurX, int &FcurY)
{
    count = a.row * a.col;
    curX = 1;
    curY = 1;
    FcurX = 1;
    FcurY = 1;
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
void showTime(int &timeleft, time_t oriTime, int &menu, bool &eot, int score, time_t &suggtime, BoardState a, bool &endsugg)
{
    time_t nowTime = time(0);
    timeleft = 220 - (difftime(nowTime, oriTime));
    if (timeleft < 0)
        endGame(menu, eot, score, a);
    if (suggtime)
        if(difftime(nowTime, suggtime) >= 5)
        {
            suggtime = 0;
            endsugg = true;
        }
    SetColor(6);
    gotoxy(6, (a.col + 2) * 5 + 5);
    cout << "##############################" << endl;
    gotoxy(7, (a.col + 2) * 5 + 5);
    cout << "# Time left: " << setw(3) << setfill(' ') << timeleft << "             #" << endl;
    gotoxy(8, (a.col + 2) * 5 + 5);
    cout << "# Press H for hints          #" << endl;
    gotoxy(9, (a.col + 2) * 5 + 5);
    cout << "# Press Esc for exit         #" << endl;
    gotoxy(10, (a.col + 2) * 5 + 5);
    cout << "##############################" << endl;
}

void endGame(int &menu, bool &eot, int score, BoardState a)
{
    SetColor(6);
    gotoxy(12, (a.col + 2) * 5 + 5);
    cout << "Time end!";
    gotoxy(13, (a.col + 2) * 5 + 5);
    cout << "Your score: " << score;
    gotoxy(14, (a.col + 2) * 5 + 5);
    cout << "Press any key to continue...";
    getch();
    menu = 1;
    eot = true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// void playMusic()
// {
//   PlaySound(TEXT("others\\music_1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
// }
