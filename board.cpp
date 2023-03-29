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

    while(true){
        if ((int) (gen - 'A' + 1) * 4 < a.row * a.col){
            for (int i = 1; (i <= 4) && (count <= a.row * a.col); ){
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
    ShowConsoleCursor(false);
    SetColor(6);
    for (int i = 0; i <= a.col + 1; i++)
        cout << "#####";
    cout << "####" << endl;
    for (int i = 0; i <= a.row + 1; i++){
        cout << "# ";
        for (int j = 0; j <= a.col + 1; j++){
            if (a.board[i][j] != 0){
                if (x == i && y == j)
                    SetColor(2);
                else if (curX == i && curY == j)
                    SetColor(6);
                else if (suggtime && ((sugx1 == i && sugy1 == j) || (sugx2 == i && sugy2 == j)))
                    SetColor(4);
                else
                    SetColor(a.board[i][j] % 7 + 9);
                cout << "-----";
            }
            else if (curX == i && curY == j){
                SetColor(6);
                for (int i1 = 0; i1 < 5; i1++)
                    cout << a.display[i * 3][j * 5 + i1];
            }
            else{
                SetColor(7);
                for (int i1 = 0; i1 < 5; i1++)
                    cout << a.display[i * 3][j * 5 + i1];
            }
        }
        SetColor(6);
        cout << " #" << endl;
        cout << "# ";
        
        for (int j = 0; j <= a.col + 1; j++){
            if (a.board[i][j] != 0)
            {
                if (nmCheck && nightmare[i][j])
                {
                    if (x == i && y == j)
                        SetColor(2);
                    else if (curX == i && curY == j)
                        SetColor(6);
                    else if (suggtime && ((sugx1 == i && sugy1 == j) || (sugx2 == i && sugy2 == j)))
                        SetColor(4);
                    else
                        SetColor(a.board[i][j] % 7 + 9);
                    cout << "|     |";
                }          
                else
                {
                    if (x == i && y == j)
                        SetColor(2);
                    else if (curX == i && curY == j)
                        SetColor(6);
                    else if (suggtime && ((sugx1 == i && sugy1 == j) || (sugx2 == i && sugy2 == j)))
                        SetColor(4);
                    else
                        SetColor(a.board[i][j] % 7 + 9);
                    cout << "| " << (char) a.board[i][j] << " |";
                }   
            }
            else if (curX == i && curY == j){
                SetColor(6);
                for (int i1 = 0; i1 < 2; i1++)
                    cout << a.display[i * 3 + 1][j * 5 + i1];
                cout << "@";
                for (int i1 = 3; i1 < 5; i1++)
                    cout << a.display[i * 3 + 1][j * 5 + i1];
            }
            else {
                SetColor(7);
                for (int i1 = 0; i1 < 5; i1++)
                    cout << a.display[i * 3 + 1][j * 5 + i1];
            }
        }
        SetColor(6);
        cout << " #" << endl;
        cout << "# ";
        
        for (int j = 0; j <= a.col + 1; j++){

            if (a.board[i][j] != 0){
                if (x == i && y == j)
                    SetColor(2);
                else if (curX == i && curY == j)
                    SetColor(6);
                else if (suggtime && ((sugx1 == i && sugy1 == j) || (sugx2 == i && sugy2 == j)))
                    SetColor(4);
                else
                    SetColor(a.board[i][j] % 7 + 9);
                cout << "-----";
            }
            else if (curX == i && curY == j){
                SetColor(6);
                for (int i1 = 0; i1 < 5; i1++)
                    cout << a.display[i * 3 + 2][j * 5 + i1];
            }
            else{
                SetColor(7);
                for (int i1 = 0; i1 < 5; i1++)
                    cout << a.display[i * 3 + 2][j * 5 + i1];
            }
        }
        SetColor(6);
        cout << " #" << endl;
    }

    for (int i = 0; i <= a.col + 1; i++)
        cout << "#####";
    cout << "####" << endl;
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

/////////////////////////////////
void deleteArt(BoardState &a){
    for (int i = 0; i < 3 * (a.row + 2); i++)
        delete[] a.display[i];
    delete[] a.display;
}

void generateArt(BoardState &a){
    a.display = new char*[3 * (a.row + 2)];
    for (int i = 0; i < 3 * (a.row + 2); i++)
        a.display[i] = new char[5 * (a.col + 2)];

    ifstream ifs;
        ifs.open("others\\art_1.txt");
    if(!ifs.is_open()){
        srand(time(0));
        for (int i = 0; i < 3 * (a.row + 2); i++){
            for (int j = 0; j < 5 * (a.col + 2); j++){
                a.display[i][j] = '.';
            }
        }
    }
    else{
        for (int i = 0; i < 3 * (a.row + 2); i++){
            string str;
            getline(ifs, str, '\n');
            for (int j = 0; j < 5 * (a.col + 2); j++){
                a.display[i][j] = str[j];
            }
        }
    }
    ifs.close();
}

void drawLine(int line[][2])
{
    SetColor(2);
    for (int k = 0; k < 3; k++)
    {
        if(line[k+1][0] == 0 && line[k+1][1] == 0)
            break;
        SHORT x1 = line[k][0], x2 = line[k+1][0], y1 = line[k][1], y2 = line[k+1][1];
        if (x1 == x2)
        {
            if (y1 > y2)
                swap (y1, y2);
            for (SHORT i = y1 * 5 + 4; i <= y2 * 5 + 4; i++)
                {
                    cursor((SHORT)i, (SHORT)(x1 * 3 + 3));
                    cout << '@';
                }
        }
        else
        {
            if (x1 > x2)
                swap (x1, x2);
            for (SHORT i = x1 * 3 + 3; i <= x2 * 3 + 3; i++)
                {
                    cursor((SHORT)(y1 * 5 + 4), (SHORT)i);
                    cout << '@';
                }
        }
    }
}

