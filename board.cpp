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

void showBoard(BoardState a, int curX, int curY, int &FcurX, int &FcurY, int &x1, int &y1, int &x2, int &y2, bool nmCheck, bool **nightmare, time_t suggtime, bool &endsugg, int sugx1, int sugy1, int sugx2, int sugy2, bool &newgame, bool &return0, int line[][2]){
    ShowConsoleCursor(false);
    if(newgame)
    {
        SetColor(6);
        for (int i = 0; i <= a.col + 1; i++)
            cout << "#####";
        cout << "####" << endl;
        for (int i = 0; i <= a.row + 1; i++){
            cout << "# ";
            for (int j = 0; j <= a.col + 1; j++){
                if (a.board[i][j] != 0){
                    if (curX == i && curY == j)
                        SetColor(6);
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
                    if (curX == i && curY == j)
                        SetColor(6);
                    else
                        SetColor(a.board[i][j] % 7 + 9);
                    cout << "| " << (char) a.board[i][j] << " |";
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
                    if (curX == i && curY == j)
                        SetColor(6);
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
        newgame = false;
    }
    else
    {
        if(endsugg)
        {
            if(!nmCheck)
            {
                SetColor(a.board[sugx1][sugy1] % 7 + 9);
                gotoxy(sugx1 * 3 + 2, sugy1 * 5 + 2);
                cout << "-----";
                gotoxy(sugx1 * 3 + 3, sugy1 * 5 + 2);
                cout << "| " << (char) a.board[sugx1][sugy1] << " |";
                gotoxy(sugx1 * 3 + 4, sugy1 * 5 + 2);
                cout << "-----";
                SetColor(a.board[sugx2][sugy2] % 7 + 9);
                gotoxy(sugx2 * 3 + 2, sugy2 * 5 + 2);
                cout << "-----";
                gotoxy(sugx2 * 3 + 3, sugy2 * 5 + 2);
                cout << "| " << (char) a.board[sugx2][sugy2] << " |";
                gotoxy(sugx2 * 3 + 4, sugy2 * 5 + 2);
                cout << "-----";
            }
            endsugg = false;
        }
        if((suggtime && !nmCheck) || ((FcurX != curX) || (FcurY != curY)) || (x1 && y1) || (return0 && a.board[x1][y1]))
        {
            int x, y, x_, y_;
            if((FcurX != curX) || (FcurY != curY))
            {
                SetColor(6);
                x = curX;
                y = curY;
                x_ = FcurX;
                y_ = FcurY;
            }
            else if(return0 && a.board[x1][y1])
            {
                if(curX == x1 && curY == y1)
                    SetColor(6);
                else
                    SetColor(a.board[x1][y1] % 7 + 9);
                x = x1;
                y = y1;
                x_ = 0;
                y_ = 0;
            }
            else if(x1 && y1)
            {
                SetColor(2);
                x = x1;
                y = y1;
                x_ = 0;
                y_ = 0;
            }
            else if(suggtime && !nmCheck)
            {
                if(((curX != sugx1) || (curY != sugy1)) && ((curX != sugx2) || (curY != sugy2)))
                {
                    SetColor(4);
                    x = sugx1;
                    y = sugy1;
                    x_ = sugx2;
                    y_ = sugy2;
                }
                else
                {
                    x = 0;
                    y = 0;
                    x_ = 0;
                    y_ = 0;
                }
            }
            if(!((curX == x1 && curY == y1) && ((FcurX != curX) || (FcurY != curY))))
            {
                if(((FcurX != curX) || (FcurY != curY)) && a.board[curX][curY] == 0)
                {
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
                else if(x)
                {
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
            }
            if(x_ && ((FcurX != x1) || (FcurY != y1)))
            {
                if(((FcurX != curX) || (FcurY != curY)) && a.board[FcurX][FcurY] == 0)
                {
                    SetColor(7);
                    gotoxy(x_ * 3 + 2, y_ * 5 + 2);
                    for(int i = 0; i < 5; i++)
                        cout << a.display[x_ * 3][y_ * 5 + i];
                    gotoxy(x_ * 3 + 3, y_ * 5 + 2);
                    for(int i = 0; i < 5; i++)
                        cout << a.display[x_ * 3 + 1][y_ * 5 + i];
                    gotoxy(x_ * 3 + 4, y_ * 5 + 2);
                    for(int i = 0; i < 5; i++)
                        cout << a.display[x_ * 3 + 2][y_ * 5 + i];
                }
                else
                {
                    if((FcurX != curX) || (FcurY != curY))
                        if(nmCheck && nightmare[x_][y_])
                            SetColor(7);
                        else
                            SetColor(a.board[FcurX][FcurY] % 7 + 9);
                    if(!nmCheck && (suggtime && (((FcurX == sugx1) && (FcurY == sugy1)) || ((FcurX == sugx2) && (FcurY == sugy2)))))
                        SetColor(4);
                    gotoxy(x_ * 3 + 2, y_ * 5 + 2);
                    cout << "-----";
                    gotoxy(x_ * 3 + 3, y_ * 5 + 2);
                    if(nmCheck && nightmare[x_][y_])
                        cout << "|   |";
                    else
                        cout << "| " << (char) a.board[x_][y_] << " |";
                    gotoxy(x_ * 3 + 4, y_ * 5 + 2);
                    cout << "-----";
                }
            }
            if(return0 && a.board[x1][y1])
            {
                x1 = 0;
                y1 = 0;
                x2 = 0;
                y2 = 0;
                return0 = false;
            }
            FcurX = curX;
            FcurY = curY;
        }
        if(return0 && a.board[x1][y1] == 0)
        {
            for (int k = 0; k < 3; k++)
            {
                if(line[k+1][0] == 0 && line[k+1][1] == 0)
                {
                    SetColor(6);
                    gotoxy(line[k][0] * 3 + 2, line[k][1] * 5 + 2);
                    for(int i = 0; i < 5; i++)
                        cout << a.display[line[k][0] * 3][line[k][1] * 5 + i];
                    gotoxy(line[k][0] * 3 + 3, line[k][1] * 5 + 2);
                    for(int i = 0; i < 2; i++)
                        cout << a.display[line[k][0] * 3 + 1][line[k][1] * 5 + i];
                    cout << '@';
                    for(int i = 3; i < 5; i++)
                        cout << a.display[line[k][0] * 3 + 1][line[k][1] * 5 + i];
                    gotoxy(line[k][0] * 3 + 4, line[k][1] * 5 + 2);
                    for(int i = 0; i < 5; i++)
                        cout << a.display[line[k][0] * 3 + 2][line[k][1] * 5 + i];
                    break;
                }
                SetColor(7);
                SHORT x3 = line[k][0], x4 = line[k+1][0], y3 = line[k][1], y4 = line[k+1][1];
                if(k == 0)
                {
                    gotoxy(x3 * 3 + 2, y3 * 5 + 2);
                    for(int i = 0; i < 5; i++)
                        cout << a.display[x3 * 3][y3 * 5 + i];
                    gotoxy(x3 * 3 + 3, y3 * 5 + 2);
                    for(int i = 0; i < 5; i++)
                        cout << a.display[x3 * 3 + 1][y3 * 5 + i];
                    gotoxy(x3 * 3 + 4, y3 * 5 + 2);
                    for(int i = 0; i < 5; i++)
                        cout << a.display[x3 * 3 + 2][y3 * 5 + i];
                }
                if (x3 == x4)
                {
                    if (y3 > y4)
                        swap (y3, y4);
                    for (SHORT i = y3 * 5 + 4; i <= y4 * 5 + 4; i++)
                        {
                            cursor((SHORT)i, (SHORT)(x3 * 3 + 3));
                            //cout << "0";
                            cout << a.display[x3 * 3 + 1][i-2];
                        }
                }
                else
                {
                    if (x3 > x4)
                        swap (x3, x4);
                    for (SHORT i = x3 * 3 + 3; i <= x4 * 3 + 3; i++)
                        {
                            cursor((SHORT)(y3 * 5 + 4), (SHORT)i);
                            //cout << "0";
                            cout << a.display[i-2][y1 * 5 + 2];
                        }
                }
                if(k == 2)
                {
                    SetColor(6);
                    gotoxy(line[k+1][0] * 3 + 2, line[k+1][1] * 5 + 2);
                    for(int i = 0; i < 5; i++)
                        cout << a.display[line[k+1][0] * 3][line[k+1][1] * 5 + i];
                    gotoxy(line[k+1][0] * 3 + 3, line[k+1][1] * 5 + 2);
                    for(int i = 0; i < 2; i++)
                        cout << a.display[line[k+1][0] * 3 + 1][line[k+1][1] * 5 + i];
                    cout << '@';
                    for(int i = 3; i < 5; i++)
                        cout << a.display[line[k+1][0] * 3 + 1][line[k+1][1] * 5 + i];
                    gotoxy(line[k+1][0] * 3 + 4, line[k+1][1] * 5 + 2);
                    for(int i = 0; i < 5; i++)
                        cout << a.display[line[k+1][0] * 3 + 2][line[k+1][1] * 5 + i];
                }
            }
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 2; j++)
                    line[i][j] = 0;
            return0 = false;
            x1 = 0;
            y1 = 0;
            x2 = 0;
            y2 = 0;
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

