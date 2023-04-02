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

void printCell(int color, int data, int x, int y, bool nmCheck, bool **nightmare){
    if(nmCheck && nightmare[x][y])
        SetColor(7);
    else
        SetColor(color);
    gotoxy(x * 3 + 2, y * 5 + 2);
    cout << "-----";
    gotoxy(x * 3 + 3, y * 5 + 2);
    if(nmCheck && nightmare[x][y])
        cout << "|   |";
    else
        cout << "| " << (char) data << " |";
    gotoxy(x * 3 + 4, y * 5 + 2);
    cout << "-----";
}

void clearCell(BoardState a, int x, int y){
    SetColor(7);
    gotoxy(x * 3 + 2, y * 5 + 2);
    for(int i = 0; i < 5; i++)
        cout << a.display[x * 3][y * 5 + i];
    gotoxy(x * 3 + 3, y * 5 + 2);
    for(int i = 0; i < 5; i++)
        cout << a.display[x * 3 + 1][y * 5 + i];
    gotoxy(x * 3 + 4, y * 5 + 2);
    for(int i = 0; i < 5; i++)
        cout << a.display[x * 3 + 2][y * 5 + i];
}

void printCursor(BoardState a, int x, int y, bool nmCheck, bool **nightmare){
    SetColor(6);
    if(a.board[x][y]){
        gotoxy(x * 3 + 2, y * 5 + 2);
        cout << "-----";
        gotoxy(x * 3 + 3, y * 5 + 2);
        if(nmCheck && nightmare[x][y])
            cout << "|   |";
        else
            cout << "| " << (char) a.board[x][y] << " |";
        gotoxy(x * 3 + 4, y * 5 + 2);
        cout << "-----";
    }
    else{
        gotoxy(x * 3 + 2, y * 5 + 2);
        for(int i = 0; i < 5; i++)
            cout << a.display[x * 3][y * 5 + i];
        gotoxy(x * 3 + 3, y * 5 + 2);
        for(int i = 0; i < 2; i++)
            cout << a.display[x * 3 + 1][y * 5 + i];
        cout << '@';
        for(int i = 3; i < 5; i++)
            cout << a.display[x * 3 + 1][y * 5 + i];
        gotoxy(x * 3 + 4, y * 5 + 2);
        for(int i = 0; i < 5; i++)
            cout << a.display[x * 3 + 2][y * 5 + i];
    }
}

void showBoard(BoardState a, int lvl, int curX, int curY, int &FcurX, int &FcurY, int &x1, int &y1, int &x2, int &y2, bool nmCheck, bool **nightmare, time_t suggtime, bool &endsugg, int sugx1, int sugy1, int sugx2, int sugy2, bool &newgame, bool &hint, bool &choose_1, bool &choose_2){
    ShowConsoleCursor(false);
    if(newgame)
    {
        SetColor(6);
        for (int i = 0; i <= a.col + 1; i++)
            cout << "#####";
        cout << "####" << endl;
        gotoxy(3 * (a.row + 2) + 2, 0);
        for (int i = 0; i <= a.col + 1; i++)
            cout << "#####";
        cout << "####" << endl;

        for (int i = 0; i <= a.row + 1; i++){
            SetColor(6);
            for (int u = 0; u < 3; u++){
                gotoxy(i * 3 + 2 + u, 0);
                cout << "# ";
                gotoxy(i * 3 + 2 + u, 5 * (a.col + 2) + 2);
                cout << " #";
            }
            for (int j = 0; j <= a.col + 1; j++)
                if(a.board[i][j])
                    printCell(a.board[i][j] % 7 + 9, a.board[i][j], i, j, nmCheck, nightmare);
                else
                    clearCell(a, i, j);
        }
        printCursor(a, 1, 1, nmCheck, nightmare);
        newgame = false;
    }
    else{
        if(endsugg){
            if(!nmCheck){
                printCell(a.board[sugx1][sugy1] % 7 + 9, a.board[sugx1][sugy1], sugx1, sugy1, nmCheck, nightmare);
                printCell(a.board[sugx2][sugy2] % 7 + 9, a.board[sugx2][sugy2], sugx2, sugy2, nmCheck, nightmare);
            }
            endsugg = false;
        }
        if((FcurX != curX) || (FcurY != curY)){
            if(FcurX == x1 && FcurY == y1)
                bool ya;
            else if(!nmCheck && ((FcurX == sugx1 && FcurY == sugy1) || (FcurX == sugx2 && FcurY == sugy2)) && suggtime)
                printCell(4, a.board[FcurX][FcurY], FcurX, FcurY, nmCheck, nightmare);
            else if(a.board[FcurX][FcurY])
                printCell(a.board[FcurX][FcurY] % 7 + 9, a.board[FcurX][FcurY], FcurX, FcurY, nmCheck, nightmare);
            else
                clearCell(a, FcurX, FcurY);
            if(curX == x1 && curY == x2)
                bool ya;
            else
                printCursor(a, curX, curY, nmCheck, nightmare);
            FcurX = curX;
            FcurY = curY;
        }
        else{
            if(choose_1){
                printCell(2, a.board[x1][y1], x1, y1, nmCheck, nightmare);
                choose_1 = false;
            }
            if(hint){
                if(!nmCheck){
                    if(sugx1 != x1 || sugy1 != y1)
                        printCell(4, a.board[sugx1][sugy1], sugx1, sugy1, nmCheck, nightmare);
                    if(sugx2 != x1 || sugy2 != y1)
                        printCell(4, a.board[sugx2][sugy2], sugx2, sugy2, nmCheck, nightmare);
                }
                hint = false;
            }
            if(choose_2){
                if(a.board[x1][y1])
                    printCell(a.board[x1][y1] % 7 + 9, a.board[x1][y1], x1, y1, nmCheck, nightmare);
                else
                    clearCell(a, x1, y1);
                printCursor(a, x2, y2, nmCheck, nightmare);
                x1 = 0, y1 = 0;
                x2 = 0, y2 = 0;
                choose_2 = false;
            }
        }
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
    for (int k = 0; k < 3; k++){
        if(line[k+1][0] == 0 && line[k+1][1] == 0)
            break;
        SHORT x1 = line[k][0], x2 = line[k+1][0], y1 = line[k][1], y2 = line[k+1][1];
        if (x1 == x2){
            if (y1 > y2)
                swap (y1, y2);
            for (SHORT i = y1 * 5 + 4; i <= y2 * 5 + 4; i++){
                    cursor((SHORT)i, (SHORT)(x1 * 3 + 3));
                    cout << '@';
                }
        }
        else{
            if (x1 > x2)
                swap (x1, x2);
            for (SHORT i = x1 * 3 + 3; i <= x2 * 3 + 3; i++){
                    cursor((SHORT)(y1 * 5 + 4), (SHORT)i);
                    cout << '@';
                }
        }
    }
}

void clearLine(int line[][2], BoardState a)
{
    SetColor(7);
    for (int k = 0; k < 3; k++){
        if(line[k+1][0] == 0 && line[k+1][1] == 0)
            break;
        SHORT x1 = line[k][0], x2 = line[k+1][0], y1 = line[k][1], y2 = line[k+1][1];
        if (x1 == x2){
            if (y1 > y2)
                swap (y1, y2);
            for (SHORT i = y1 * 5 + 4; i <= y2 * 5 + 4; i++){
                    cursor((SHORT)i, (SHORT)(x1 * 3 + 3));
                    cout << a.display[x1 * 3 + 1][i-2];;
                }
        }
        else{
            if (x1 > x2)
                swap (x1, x2);
            for (SHORT i = x1 * 3 + 3; i <= x2 * 3 + 3; i++){
                    cursor((SHORT)(y1 * 5 + 4), (SHORT)i);
                    cout << a.display[i-2][y1 * 5 + 2];
                }
        }
    }
    for (int i = 0; i < 4; i++)
        for(int u = 0; u < 2; u++)
            line[i][u] = 0;
}
