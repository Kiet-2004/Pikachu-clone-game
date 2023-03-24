#include "account.h"

void login(PlayerState &player, int &mCurX, int &menu, int &playerid, bool &succlog, SaveState &save)
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
                    {
                        if(log)
                        {
                            loadMode(save, playerid);
                            loadLB(player, playerid);
                        }
                        else
                        {
                            createGame(playerid);
                            save.mode = 0;
                        }
                    }
            }
            else
            {
                submenu = 1;
                log = true;
            }
        }
    }
}


void checkLogin(PlayerState player, int &playerid, bool &succ, int &submenu)
{
    ifstream ifs("account.dat", ios::binary);
    if(!ifs.is_open()){
        cout << "Cannot open file" << endl;
        getch();
    }
    else{
        ifs.seekg(0, ios::end);
        int n = ifs.tellg() / sizeof(PlayerState);
        ifs.seekg(0, ios::beg);
        if (n != 0)
            for (int i = 0; i < n; i++)
            {
                PlayerState something;
                ifs.read((char *) &something, sizeof(PlayerState));
                if(!strcmp(something.username, player.username))
                    if(!strcmp(something.password, player.password))
                    {
                        succ = true;
                        playerid = i;
                        break;
                    }
            }
        if(succ)
        {
            cout << "Login successfully";
            getch();
        }
        else
        {
            cout << "Wrong username or password, Stupid!";
            submenu = 1;
            getch();
        }
    }
    ifs.close();
}

void checkRegis(PlayerState &player, int &playerid, bool &succ, int &submenu, bool &log)
{
    fstream fs("account.dat", ios::out | ios::in | ios::binary);
    if(!fs.is_open()){
        cout << "Cannot open file" << endl;
    }
    else
    {
        fs.seekg(0, ios::end);
        int n = fs.tellg() / sizeof(PlayerState);
        fs.seekg(0, ios::beg);
        bool check = true;
        if (n != 0)
            for (int i = 0; i < n; i++)
            {
                PlayerState something;
                fs.read((char *) &something, sizeof(PlayerState));
                if(!strcmp(something.username, player.username))
                {
                    cout << "Username exists, fuck you.";
                    check = false;
                    submenu = 1;
                    log = true;
                    getch();
                    break;
                }
            }
        if(check)
        {
            playerid = n;
            for(int i = 0; i < 5; i++)
            {
                player.hsEasy[i] = 0;
                player.hsMedium[i] = 0;
                player.hsHard[i] = 0;
                player.hsNightmare[i] = 0;
            }
            succ = true;
            fs.seekp(n*sizeof(PlayerState), ios::beg);
            fs.write((char *)&player, sizeof(player));
            cout << "Register successfully!";
            getch();
        }
    }
    fs.close();
    fs.close();
}

void saveGame(SaveState &save, int playerid, BoardState a, int mode, time_t oriTime, int lvl, int lvlcap, int count, int score)
{
    ofstream ofs("save.dat", ios::binary);
    ofs.seekp(playerid * sizeof(SaveState), ios::beg);
    save.lvlState[0] = lvl;
    save.lvlState[1] = lvlcap;
    save.row = a.row;
    save.col = a.col;
    save.count = count;
    for(int i = 0; i < save.row; i++)
        for(int j = 0; j < save.col; j++)
            save.board[i*save.col+j] = a.board[i+1][j+1];
    save.mode = mode;
    save.time = 220 - difftime(time(0), oriTime);
    save.score = score;
    ofs.write((char *)&save, sizeof(SaveState));
    ofs.close();
}

void createGame(int playerid)
{
    SaveState save;
    ofstream ofs("save.dat", ios::binary);
    ofs.seekp(playerid * sizeof(SaveState), ios::beg);
    ofs.write((char *)&save, sizeof(SaveState));
    ofs.close();
}

void loadMode(SaveState &save, int playerid)
{
    ifstream ifs("save.dat", ios::binary);
    ifs.seekg(playerid * sizeof(SaveState), ios::beg);
    SaveState temp;
    ifs.read((char *)&temp, sizeof(SaveState));
    save.mode = temp.mode;
}

void loadGame(SaveState &save, int playerid, BoardState &a, int &mode, time_t &oriTime, int &lvl, int lvlcap[], int &count, int &score)
{
    ifstream ifs("save.dat", ios::binary);
    ifs.seekg(playerid * sizeof(SaveState), ios::beg);
    ifs.read((char *)&save, sizeof(SaveState));
    a.row = save.row;
    a.col = save.col;
    a.board = new int*[a.row + 2];
    for (int i = 0; i < a.row + 2; i++)
        a.board[i] = new int[a.col + 2];
    for (int i = 0; i < a.row + 2; i++)
        for (int j = 0; j < a.col + 2; j++)
            a.board[i][j] = 0;
    for(int i = 0; i < save.row; i++)
        for(int j = 0; j < save.col; j++)
            a.board[i+1][j+1] = save.board[i*save.col+j];
    mode = save.mode;
    lvl = save.lvlState[0];
    lvlcap[0] = save.lvlState[1];
    int temp = lvl;
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
    score = save.score;
    oriTime = time(0) - (220 - save.time);
    ifs.close();
}

void loadLB(PlayerState &player, int playerid)
{
    ifstream ifs("account.dat", ios::binary);
    ifs.seekg(playerid * sizeof(PlayerState), ios::beg);
    ifs.read((char *)&player, sizeof(PlayerState));
    ifs.close();
}

void updateLB(PlayerState &player, int playerid, int mode, int score)
{
    switch(mode)
    {
        case 1:
        {
            for(int i = 0; i < 5; i++)
                if(player.hsEasy[i] < score)
                {
                    for(int u = 4; u > i + 1; u--)
                        player.hsEasy[u] = player.hsEasy[u-1];
                    player.hsEasy[i] = score;
                    break;
                }
            break;
        }
        case 2:
        {
            for(int i = 0; i < 5; i++)
                if(player.hsMedium[i] < score)
                {
                    for(int u = 4; u > i + 1; u--)
                        player.hsMedium[u] = player.hsMedium[u-1];
                    player.hsMedium[i] = score;
                    break;
                }
            break;
        }
        case 3:
        {
            for(int i = 0; i < 5; i++)
                if(player.hsHard[i] < score)
                {
                    for(int u = 4; u > i + 1; u--)
                        player.hsHard[u] = player.hsHard[u-1];
                    player.hsHard[i] = score;
                    break;
                }
            break;
        }
        case 4:
        {
            for(int i = 0; i < 5; i++)
                if(player.hsNightmare[i] < score)
                {
                    for(int u = 4; u > i + 1; u--)
                        player.hsNightmare[u] = player.hsNightmare[u-1];
                    player.hsNightmare[i] = score;
                    break;
                }
            break;
        }
    }
    ofstream ofs("account.dat", ios::binary);
    ofs.seekp(playerid * sizeof(PlayerState), ios::beg);
    ofs.write((char *)&player, sizeof(PlayerState));
    ofs.close();
}
