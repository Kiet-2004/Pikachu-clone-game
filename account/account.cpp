#include "account.h"

void readData(vector<Player> &list){
    ifstream ifs("account.dat", ios::binary);
    if(!ifs.is_open()){
        cout << "Cannot open file" << endl;
    }
    else{
        ifs.seekg(0, ios::end);
        int n = ifs.tellg() / sizeof(Player);
        ifs.seekg(0, ios::beg);
        if (n != 0){
            for (int i = 0; i < n; i++){
                Player something;
                ifs.read((char *) &something, sizeof(Player));
                list.push_back(something);
            }
        }
    }
    ifs.close();
}

void writeData(vector<Player> &list){
    ofstream ofs;
    ofs.open("account.dat", ios::binary);
    for(int i = 0; i < list.size(); i++){
        ofs.write((char *) (&list[i]), sizeof(Player));
    }
    ofs.close();
} 

void login(vector<Player> &list, Player &a, bool &flag){
    string username;
    string password;
    cout << "Please input your username: ";
    getline(cin, username);
    bool fl = false; 
    int index;
    for (int i = 0; i < list.size(); i++){
        if (username == list[i].username){
            fl = true;
            index = i;
            break;
        }
    }
    if(fl){
        cout << "Please input your password: ";
        int attemps = 5;
        while (attemps--){
            getline(cin, password);
            if(password == list[index].password){
                cout << "Successfully" << endl;
                a.currentGamemode = list[index].currentGamemode;
                a.currentLvl = list[index].currentLvl;
                a.highscore = list[index].highscore;
                strcpy(a.username, list[index].username);
                strcpy(a.password, list[index].password);
                flag = true;
                break;
            }
            else {
                cout << "Invalid password. Please retry: " << endl;
            }
        }
    }
    else{
        cout << "There is no such username" << endl;
    }
}

void signUp(vector<Player> &list, Player &a, bool &flag){
    Player signup;
    cout << "Please input your username: ";
    string b;
    getline(cin, b);
    if (b.length() > 29){
        cout << "Username length is too long" << endl;
        return;
    }
    strcpy(signup.username, b.c_str());
    for (int i = 0; i < list.size(); i++){
        if (strcmp(signup.username, list[i].username) == 0){
            cout << "This username is already existed" << endl;
            return;
        }
    }
    cout << "Please input your password: ";
    getline(cin, b);
    if (b.length() > 29){
        cout << "Username length is too long" << endl;
        return;
    }
    strcpy(signup.password, b.c_str());
    signup.currentLvl = 1;
    signup.currentGamemode = 1;
    signup.highscore = 1;
    a.currentGamemode = signup.currentGamemode;
    a.currentLvl = signup.currentLvl;
    a.highscore = signup.highscore;
    strcpy(a.username, signup.username);
    strcpy(a.password, signup.password);
    flag = true;
    list.push_back(signup);
}