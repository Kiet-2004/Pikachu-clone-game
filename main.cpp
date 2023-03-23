#include "header.h"
#include <stdlib.h>

int main(){
    //playMusic();
    MoveWindow(0, 0);
    ShowConsoleCursor(false);
    
    BoardState board;
    board.row = 4;
    board.col = 6;

    int count = 4, lvl = 1, lvlcap[] = {1, 0, 0, 1};
    int curX = 1, curY = 1, x1 = 0, x2 = 0, y1 = 0, y2 = 0, line[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    int mSelect = 1, mCurX = 1, mCurY = 1;
    time_t oriTime;
    bool nmCheck = false, **nightmare;
    while(true){
        while (mSelect > 0 && mSelect < 4)
        {
            ClearScreen();
            generateMenu(board, mSelect, mCurX, mCurY, nmCheck);
        }
        if (mSelect == 0)
            break;
        else if (mSelect == 4)
        {
            count = board.row * board.col;
            curX = 1;
            curY = 1;
            lvl = 1;
            lvlcap[0] = 1;
            lvlcap[1] = 0;
            lvlcap[2] = 0;
            lvlcap[3] = 1;
            ClearScreen();
            generateBoard(board);
            generateArt(board);
            if (nmCheck)
                generateNightmare(board, nightmare);
            while(!checkLegalMove(board))
                resetBoard(board);
            mSelect++;
            oriTime = time(0) - min(lvl, 100);
        }
        else if (mSelect == 5)
        {
            while(mSelect == 5 && !(x1 && y1 && x2 && y2))
            {
                cursor(0, 0);
                cout << "\t\t\tLevel: " << lvl << "\t\t\t\t" << endl;
                showBoard(board, curX, curY, x1, y1, nightmare, nmCheck);
                showTime(oriTime, mSelect);
                if(kbhit())
                    keyboardSelect(board, curX, curY, x1, y1, x2, y2, mSelect);
            }
            if (mSelect == 5)
            {
                if (findPath(board, x1, x2, y1, y2, line)){
                    board.board[x1][y1] = 0;
                    board.board[x2][y2] = 0;
                    count -= 2;
                    drawLine(line);
                    Sleep(150);
                    levelCheck(board, x1, y1, x2, y2, lvl, lvlcap);
                    if (count)
                        while (!checkLegalMove(board))
                            resetBoard(board);
                }
                if (nmCheck)
                    resetNightmare(board, nightmare);
                x1 = 0;
                y1 = 0;
                x2 = 0;
                y2 = 0;
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 2; j++)
                        line[i][j] = 0;
                if (!count)
                {
                    cursor(0, 1);
                    curX = board.row + 2, curY = board.col + 2;
                    showBoard(board, curX, curY, x1, y1, nightmare, nmCheck);
                    cout << endl << endl << endl << "Victory royale!!!!" << endl << endl;
                    string ch ="";
                    while (ch != "Y" && ch != "N" && ch != "y" && ch != "n")
                    {
                        cout << "Continue(Y/N)?: ";
                        getline(cin, ch);
                    }
                    if(ch == "Y" || ch == "y")
                    {
                        lvl++;
                        if (lvlcap[3] < 9)
                        {
                            lvlcap[3]++;
                        }
                        else
                        {
                            if (lvlcap[2] < 9)
                            {
                                lvlcap[2]++;
                            }
                            else
                            {
                                lvlcap[1]++;
                                lvlcap[2] = lvlcap[1];
                            }
                            lvlcap[3] = lvlcap[2] + 1;
                        }
                        count = board.row * board.col;
                        deleteMem(board);
                        deleteArt(board);
                        generateBoard(board);
                        while(!checkLegalMove(board))
                            resetBoard(board);
                        generateArt(board);
                        if (nmCheck)
                        {
                            deleteNightmare(board, nightmare);
                            generateNightmare(board, nightmare);
                        }
                        curX = 1;
                        curY = 1;
                        lvlcap[0] = 1;
                        ClearScreen();
                        oriTime = time(0) - min(lvl, 100);
                    }
                    else
                    {
                        deleteMem(board);
                        deleteArt(board);
                        if (nmCheck)
                        {
                            deleteNightmare(board, nightmare);
                            nmCheck = false;
                        }
                        mSelect = 1;
                        board.row = 4;
                        board.col = 6;
                        mCurX = 1;
                        mCurY = 1;
                    }
                }
            }
            else
            {
                deleteMem(board);
                deleteArt(board);
                if (nmCheck)
                {
                    deleteNightmare(board, nightmare);
                    nmCheck = false;
                }
                board.row = 4;
                board.col = 6;
                x1 = 0;
                x2 = 0;
                y1 = 0;
                y2 = 0;
                mCurX = 1;
                mCurY = 1;
            }
        }
    }
    return 0;
}
