#include "board.h"

void deleteMem(BoardState &a){
    for (int i = 0; i < a.row + 2; i++)
        delete[] a.board[i];
    delete[] a.board;
}

void generateBoard(BoardState &a){
    a.board = new int*[a.row + 2];
    for (int i = 0; i < a.row + 2; i++)
        a.board[i] = new int[a.col + 2];

    for (int i = 0; i < a.row + 2; i++)
        for (int j = 0; j < a.col + 2; j++)
            a.board[i][j] = 0;

    int count = 0;
    char gen = 'A';
    srand(time(0));
    int maxNum = 4;

    while(true){
        if ((int) (gen - 'A' + 1) * maxNum < a.row * a.col){
            for (int i = 1; (i <= maxNum) && (count <= a.row * a.col); ){
                int x = rand() % a.row + 1;
                int y = rand() % a.col + 1;
                if (a.board[x][y] == 0){
                    i++;
                    a.board[x][y] = (int) gen;
                    count ++;
                }
            }
            gen++;
        }
        else {
            for (int i = 1; i <= a.row; i++)
                for (int j = 1; j <= a.col; j++)
                    if (a.board[i][j] == 0){
                        a.board[i][j] = (int) gen;
                        count++;
                    }
        }
        if (count >= a.row * a.col){
            break;
        }
    }

}

void showBoard(BoardState a, int curX, int curY, int x, int y, bool **nightmare, bool nmCheck, time_t suggtime, int sugx1, int sugy1, int sugx2, int sugy2){

    for (int i = 0; i <= a.row + 1; i++){
        for (int j = 0; j <= a.col + 1; j++){
            if (a.board[i][j] != 0)
                cout << "#######";
            else
                for (int i1 = 0; i1 < 7; i1++)
                    cout << a.display[i * 5][j * 7 + i1];
        }
        cout << endl;

        for (int j = 0; j <= a.col + 1; j++){
            if (a.board[i][j] != 0)
            {
                if (x == i && y == j)
                    cout << "# / / #";
                else
                    cout << "#     #";
            }
            else
                for (int i1 = 0; i1 < 7; i1++)
                    cout << a.display[i * 5 + 1][j * 7 + i1];
        }
        cout << endl;

        for (int j = 0; j <= a.col + 1; j++){
            if (a.board[i][j] != 0)
            {
                if (nmCheck)
                {
                    if(nightmare[i][j])
                    {
                        if (curX == i && curY == j)
                            cout << "# < > #";
                        else
                            cout << "#     #";
                    }
                    else
                    {
                        if (curX == i && curY == j)
                        {
                            if (suggtime && ((sugx1 == i && sugy1 == j) || (sugx2 == i && sugy2 == j)))
                                cout << "# <" << (char) (a.board[i][j]+32) << "> #";
                            else
                                cout << "# <" << (char) a.board[i][j] << "> #";
                        }
                        else
                        {
                            if (suggtime && ((sugx1 == i && sugy1 == j) || (sugx2 == i && sugy2 == j)))
                                cout << "#  " << (char) (a.board[i][j]+32) << "  #";
                            else
                                cout << "#  " << (char) a.board[i][j] << "  #";
                        }
                    }
                }
                else
                {
                    if (curX == i && curY == j)
                    {
                        if (suggtime && ((sugx1 == i && sugy1 == j) || (sugx2 == i && sugy2 == j)))
                            cout << "# <" << (char) (a.board[i][j]+32) << "> #";
                        else
                            cout << "# <" << (char) a.board[i][j] << "> #";
                    }
                    else
                    {
                        if (suggtime && ((sugx1 == i && sugy1 == j) || (sugx2 == i && sugy2 == j)))
                            cout << "#  " << (char) (a.board[i][j]+32) << "  #";
                        else
                            cout << "#  " << (char) a.board[i][j] << "  #";
                    }
                }
            }
            else if (curX == i && curY == j)
                cout << "%&<*>$7";
            else
                for (int i1 = 0; i1 < 7; i1++)
                    cout << a.display[i * 5 + 2][j * 7 + i1];
        }
        cout << endl;

        for (int j = 0; j <= a.col + 1; j++){
            if (a.board[i][j] != 0)
            {
                if (x == i && y == j)
                    cout << "# / / #";
                else
                    cout << "#     #";
            }
            else
                for (int i1 = 0; i1 < 7; i1++)
                    cout << a.display[i * 5 + 3][j * 7 + i1];
        }
        cout << endl;

        for (int j = 0; j <= a.col + 1; j++){
            if (a.board[i][j] != 0)
                cout << "#######";
            else
                for (int i1 = 0; i1 < 7; i1++)
                    cout << a.display[i * 5 + 4][j * 7 + i1];
        }
        cout << endl;
    }
}

void resetBoard(BoardState a){
    int cnt[26];
    for (int i = 0; i < 26; i++)
        cnt[i] = 0;

    for (int i = 1; i <= a.row; i++){
        for (int j = 1; j <= a.col; j++){
            if(a.board[i][j] != 0){
                cnt[a.board[i][j] - (int) 'A'] ++;
                a.board[i][j] = -1;
            }
        }
    }

    srand(time(0));
    for (int i = 1; i <= a.row; i++){
        for (int j = 1; j <= a.col; j++){
            if (a.board[i][j] == -1)
                while (true){
                    char gen = (char) (rand() % 25 + (int)'A');
                    if (cnt[(int) (gen - 'A')] > 0){
                        a.board[i][j] = (int) gen;
                        cnt[(int) (gen - 'A')]--;
                        break;
                    }
                }
        }
    }
}
