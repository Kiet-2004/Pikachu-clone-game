#include "account.h"

void login(PlayerState &player, BoardState &a, int &mCurX, int &menu, int &playerid, bool &succlog, int lvlcap[], time_t &oriTime)
{
    bool log = true;
    int submenu = 1;
    while(!succlog)
    {
        ClearScreen();
        cout << endl << "\t\tPikachuchu" << endl << endl;
        if(submenu == 1)
        {
            if (mCurX == 1)
            {
                cout << "\t\t< LOGIN >" << endl;
                cout << "\t\t  REGISTER  " << endl;
                cout << "\t\t  QUIT  " << endl;
            }
            else if (mCurX == 2)
            {
                cout << "\t\t  LOGIN  " << endl;
                cout << "\t\t< REGISTER >" << endl;
                cout << "\t\t  QUIT  " << endl;
            }
            else if (mCurX == 3)
            {
                cout << "\t\t  LOGIN  " << endl;
                cout << "\t\t  REGISTER  " << endl;
                cout << "\t\t< QUIT >" << endl;
            }
            int c = getch(), ch;
            if(c == 224)
                switch(ch = getch())
                {
                    case KEY_UP:
                    {
                        if(mCurX > 1)
                            mCurX--;
                        else
                            mCurX = 3;
                        break;
                    }
                    case KEY_DOWN:
                    {
                        if(mCurX < 3)
                            mCurX++;
                        else
                            mCurX = 1;
                        break;
                    }
                }
            else if(c == KEY_SPACE)
            {
                if(mCurX == 3)
                {
                    menu = 0;
                    succlog = true;
                }
                else
                {
                    if(mCurX == 2)
                        log = false;
                    mCurX = 1;
                    submenu++;
                }
            }
        }
        else
        {
            cout << "\t\t  Enter username: ";
            cin.getline(player.username, 33);
            cout << "\t\t  Enter password: ";
            cin.getline(player.password, 33);
            if(strlen(player.username) && strlen(player.password))
            {
                if (log)
                    checkLogin(player, playerid, succlog, submenu);
                else
                    checkRegis(player, playerid, succlog, submenu, log);
                if(succlog)
                    loadGame(player, playerid, a, lvlcap, oriTime);
            }
            else
            {
                cout << "invalid!";
                getch();
                submenu = 1;
                log = true;
            }
        }
    }
}

void checkLogin(PlayerState player, int &playerid, bool &succ, int &submenu)
{
    ifstream ifs("account.dat", ios::binary);
    int n = 0;
    ifs.seekg(0, ios::end);
    int len = ifs.tellg();
    ifs.seekg(0, ios::beg);
    while(ifs.tellg() < len)
    {
        char usercheck[32], passcheck[32];
        ifs.read((char *)usercheck, 32);
        ifs.read((char *)passcheck, 32);
        ifs.seekg(608, ios::cur);
        if(!strcmp(usercheck, player.username) && !strcmp(passcheck, player.password))
        {
            succ = true;
            playerid = n;
            break;
        }
        n++;
    }
    if(succ)
        cout << "Login successfully";
    else
    {
        cout << "Wrong username or password, Stupid!";
        submenu = 1;
    }
    getch();
    ifs.close();
}

void checkRegis(PlayerState &player, int &playerid, bool &succ, int &submenu, bool &log)
{
    fstream fs("account.dat", ios::out | ios::in | ios::binary);
    int n = 0;
    bool check = true;
    fs.seekg(0, ios::end);
    int len = fs.tellg();
    fs.seekg(0, ios::beg);
    while(fs.tellg() < len)
    {
        char usercheck[32];
        fs.read((char *)usercheck, 32);
        fs.seekg(640, ios::cur);
        if(!strcmp(usercheck, player.username))
        {
            cout << "Username exists, fuck you.";
            check = false;
            submenu = 1;
            log = true;
            getch();
            break;
        }
        n++;
    }
    if(check)
    {
        playerid = n;
        player.mode = 0;
        player.lvl = 1;
        player.lvlstate = 1;
        player.count = 24;
        player.timeleft = 220;
        player.score = 0;
        int board[2] = {4, 6};
        fs.seekp(0, ios::end);
        fs.write((char *)&player, sizeof(player));
        fs.write((char *)board, 584);
        succ = true;
        cout << "Register successfully!";
        getch();
    }
    fs.close();
}

void saveGame(PlayerState player, int playerid, BoardState a)
{
    fstream fs("account.dat", ios::binary | ios::in | ios::out);
    fs.seekp(playerid * 672, ios::beg);
    fs.write((char *)&player, sizeof(player));
    fs.write((char *)&a.row, 4);
    fs.write((char *)&a.col, 4);
    for(int i = 0; i < a.row + 2; i++)
        fs.write((char *)a.board[i], (a.col + 2)*4);
    int temp = 0;
    for(int i = 0; i < 144 - (a.row+2)*(a.col+2); i++)
        fs.write((char *)&temp, 4);
    fs.close();
}

void loadGame(PlayerState &player, int playerid, BoardState &a, int lvlcap[], time_t &oriTime)
{
    ifstream ifs("account.dat", ios::binary);
    ifs.seekg(playerid * 672, ios::beg);
    ifs.read((char *)&player, sizeof(player));
    cout << sizeof(player);
    ifs.read((char *)&a.row, 4);
    ifs.read((char *)&a.col, 4);
    if(player.mode)
    {
        a.board = new int*[a.row + 2];
        for (int i = 0; i < a.row + 2; i++)
            a.board[i] = new int[a.col + 2];
        for(int i = 0; i < a.row + 2; i++)
            ifs.read((char *)a.board[i], (a.col + 2)*4);
    }
    int temp = player.lvl;
    while(temp - (9 - lvlcap[8]) > 0)
    {
        temp -= (9 - lvlcap[8]);
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
    lvlcap[9] = temp + lvlcap[8];
    oriTime = time(0) - (220 - player.timeleft);
    ifs.close();
}

void loadLB(LeaderBoard &lb)
{
    fstream fs("lb.dat", ios::in | ios::out | ios::binary);
    fs.read((char *)&lb, sizeof(lb));
    fs.close();
}

void updateLB(LeaderBoard &lb, PlayerState player)
{
    switch(player.mode)
    {
        case 1:
        {
            for(int i = 0; i < 5; i++)
                if(lb.hsEasy[i] < player.score)
                {
                    for(int u = 4; u > i; u--)
                    {
                        lb.hsEasy[u] = lb.hsEasy[u-1];
                        strcpy(lb.userEasy[u], lb.userEasy[u-1]);
                    }
                    lb.hsEasy[i] = player.score;
                    strcpy(lb.userEasy[i], player.username);
                    break;
                }
            break;
        }
        case 2:
        {
            for(int i = 0; i < 5; i++)
                if(lb.hsMedium[i] < player.score)
                {
                    for(int u = 4; u > i; u--)
                    {
                        lb.hsMedium[u] = lb.hsMedium[u-1];
                        strcpy(lb.userMedium[u], lb.userMedium[u-1]);
                    }
                    lb.hsMedium[i] = player.score;
                    strcpy(lb.userMedium[i], player.username);
                    break;
                }
            break;
        }
        case 3:
        {
            for(int i = 0; i < 5; i++)
                if(lb.hsHard[i] < player.score)
                {
                    for(int u = 4; u > i; u--)
                    {
                        lb.hsHard[u] = lb.hsHard[u-1];
                        strcpy(lb.userHard[u], lb.userHard[u-1]);
                    }
                    lb.hsHard[i] = player.score;
                    strcpy(lb.userHard[i], player.username);
                    break;
                }
            break;
        }
        case 4:
        {
            for(int i = 0; i < 5; i++)
                if(lb.hsNightmare[i] < player.score)
                {
                    for(int u = 4; u > i; u--)
                    {
                        lb.hsNightmare[u] = lb.hsNightmare[u-1];
                        strcpy(lb.userNightmare[u], lb.userNightmare[u-1]);
                    }
                    lb.hsNightmare[i] = player.score;
                    strcpy(lb.userNightmare[i], player.username);
                    break;
                }
            break;
        }
    }
    ofstream ofs("lb.dat", ios::binary);
    ofs.write((char *)&lb, sizeof(lb));
    ofs.close();
}
