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
    strcpy(a.username, signup.username);
    strcpy(a.password, signup.password);
    flag = true;
    list.push_back(signup);
}

void readSaveFile(vector<Save> &a){
    ifstream ifs("save.dat", ios::binary);
    if(!ifs.is_open()){
        cout << "Cannot open file" << endl;
    }
    else{
        ifs.seekg(0, ios::end);
        if (ifs.tellg() != 0){
            int size = (int) ifs.tellg();
            ifs.seekg(0, ios::beg);
            while(ifs.tellg() < size){
                Save cur;
                ifs.read(cur.username, 30);
                ifs.read((char *) &cur.currentGamemode, sizeof(int));
                ifs.read((char *) &cur.currentLvl, sizeof(int));
                ifs.read((char *) &cur.timeLeft, sizeof(int));
                ifs.read((char *) &cur.row, sizeof(int));
                ifs.read((char *) &cur.col, sizeof(int));
                cur.board = new int*[cur.row + 2];
                for (int i = 0; i < cur.row + 2; i++){
                    cur.board[i] = new int[cur.col + 2];
                    ifs.read((char *) cur.board[i], sizeof(int) * (cur.col + 2));
                }
                a.push_back(cur);
            }
        }
    }
    ifs.close();
}

void writeSaveFile(vector<Save> &a){
    ofstream ofs;
    ofs.open("save.dat", ios::binary);
    for(int i = 0; i < a.size(); i++){
        ofs.write(a[i].username, 30);
        ofs.write((char *) &a[i].currentGamemode, sizeof(int));
        ofs.write((char *) &a[i].currentLvl, sizeof(int));
        ofs.write((char *) &a[i].timeLeft, sizeof(int));
        ofs.write((char *) &a[i].row, sizeof(int));
        ofs.write((char *) &a[i].col, sizeof(int));
        for (int j = 0; j < a[i].row + 2; j++){
            ofs.write((char *) a[i].board[j], sizeof(int) * (a[i].col + 2));
            delete[] a[i].board[j];
        }
        delete[] a[i].board;
    }
    ofs.close();
}