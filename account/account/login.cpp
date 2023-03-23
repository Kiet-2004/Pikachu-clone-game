#include "account.cpp"

int main(){
    vector<Player> list;
    vector<Save> save;
    Player currentPlayer;
    bool flag = false;
    readData(list);
    while (true){
        int n; 
        cin >> n;
        cin.ignore();
        if (n == 0) break;
        else if (n == 1) {
            signUp(list, currentPlayer, flag);
            writeData(list);
        }
        else if (n == 2) {
            login(list, currentPlayer, flag);
        }

        if (flag) break;
    }

    cout << "Username: " << currentPlayer.username << endl;

    return 0;
}
