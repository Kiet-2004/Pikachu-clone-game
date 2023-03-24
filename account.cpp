#include "account.h"

void login(PlayerState &player, int &mCurX, int &menu, int &playerid, bool &succlog)
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

void checkRegis(PlayerState player, int &playerid, bool &succ, int &submenu, bool &log)
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
            succ = true;
            fs.seekp(n*sizeof(PlayerState), ios::end);
            fs.write((char *)&player, sizeof(player));
            cout << "Register successfully!";
            getch();
        }
    }
    fs.close();
    fs.close();
}

//void writeData(vector<Player> &list){
//    ofstream ofs;
//    ofs.open("account.dat", ios::binary);
//    for(int i = 0; i < list.size(); i++){
//        ofs.write((char *) (&list[i]), sizeof(Player));
//    }
//    ofs.close();
//}
//
//void login(vector<Player> &list, Player &a, bool &flag){
//    string username;
//    string password;
//    cout << "Please input your username: ";
//    getline(cin, username);
//    bool fl = false;
//    int index;
//    for (int i = 0; i < list.size(); i++){
//        if (username == list[i].username){
//            fl = true;
//            index = i;
//            break;
//        }
//    }
//    if(fl){
//        cout << "Please input your password: ";
//        int attemps = 5;
//        while (attemps--){
//            getline(cin, password);
//            if(password == list[index].password){
//                cout << "Successfully" << endl;
//                strcpy(a.username, list[index].username);
//                strcpy(a.password, list[index].password);
//                flag = true;
//                break;
//            }
//            else {
//                cout << "Invalid password. Please retry: " << endl;
//            }
//        }
//    }
//    else{
//        cout << "There is no such username" << endl;
//    }
//}
//
//void signUp(vector<Player> &list, Player &a, bool &flag){
//    Player signup;
//    cout << "Please input your username: ";
//    string b;
//    getline(cin, b);
//    if (b.length() > 29){
//        cout << "Username length is too long" << endl;
//        return;
//    }
//    strcpy(signup.username, b.c_str());
//    for (int i = 0; i < list.size(); i++){
//        if (strcmp(signup.username, list[i].username) == 0){
//            cout << "This username is already existed" << endl;
//            return;
//        }
//    }
//    cout << "Please input your password: ";
//    getline(cin, b);
//    if (b.length() > 29){
//        cout << "Username length is too long" << endl;
//        return;
//    }
//    strcpy(signup.password, b.c_str());
//    strcpy(a.username, signup.username);
//    strcpy(a.password, signup.password);
//    flag = true;
//    list.push_back(signup);
//}
//
//void readSaveFile(vector<Save> &a){
//    ifstream ifs("save.dat", ios::binary);
//    if(!ifs.is_open()){
//        cout << "Cannot open file" << endl;
//    }
//    else{
//        ifs.seekg(0, ios::end);
//        if (ifs.tellg() != 0){
//            int size = (int) ifs.tellg();
//            ifs.seekg(0, ios::beg);
//            while(ifs.tellg() < size){
//                Save cur;
//                ifs.read(cur.username, 30);
//                ifs.read((char *) &cur.currentGamemode, sizeof(int));
//                ifs.read((char *) &cur.currentLvl, sizeof(int));
//                ifs.read((char *) &cur.highscore, sizeof(int));
//                ifs.read((char *) &cur.row, sizeof(int));
//                ifs.read((char *) &cur.col, sizeof(int));
//                cur.board = new int*[cur.row + 2];
//                for (int i = 0; i < cur.row + 2; i++){
//                    cur.board[i] = new int[cur.col + 2];
//                    ifs.read((char *) cur.board[i], sizeof(int) * (cur.col + 2));
//                }
//                a.push_back(cur);
//            }
//        }
//    }
//    ifs.close();
//}
//
//void writeSaveFile(vector<Save> &a){
//    ofstream ofs;
//    ofs.open("save.dat", ios::binary);
//    for(int i = 0; i < a.size(); i++){
//        ofs.write(a[i].username, 30);
//        ofs.write((char *) &a[i].currentGamemode, sizeof(int));
//        ofs.write((char *) &a[i].currentLvl, sizeof(int));
//        ofs.write((char *) &a[i].highscore, sizeof(int));
//        ofs.write((char *) &a[i].row, sizeof(int));
//        ofs.write((char *) &a[i].col, sizeof(int));
//        for (int j = 0; j < a[i].row + 2; j++){
//            ofs.write((char *) a[i].board[j], sizeof(int) * (a[i].col + 2));
//            delete[] a[i].board[j];
//        }
//        delete[] a[i].board;
//    }
//    ofs.close();
//}
