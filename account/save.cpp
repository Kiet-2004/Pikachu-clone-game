#include "account.cpp"

int main(){
    vector<Save> save;
    // int k;
    // cin >> k;
    // while(k--){
    //     int m, n, **a;
    //     cin >> m >> n;
    //     a = new int*[m + 2];
    //     for (int i = 0; i < m + 2; i++){
    //         a[i] = new int[n + 2];
    //     }
    //     for (int i = 0; i < m + 2; i++){
    //         for (int j = 0; j < n + 2; j++){
    //             a[i][j] = i * j;
    //         }
    //     }
    //     Save cur;
    //     strcpy(cur.username, "kiet");
    //     cur.row = m;
    //     cur.col = n;
    //     cur.board = a;
    //     save.push_back(cur);
    // }

    readSaveFile(save);
    for (int a = 0; a < save.size(); a++){
        cout << save[a].username << endl
            << save[a].currentGamemode << endl
            << save[a].currentLvl << endl
            << save[a].highscore << endl
            << save[a].row << endl
            << save[a].col << endl;
        for (int i = 0; i < save[a].row + 2; i++){
            for (int j = 0; j < save[a].col + 2; j++){
                cout << save[a].board[i][j] << " ";
            }
            cout << endl;
        }
    }

    writeSaveFile(save);
    return 0;
}