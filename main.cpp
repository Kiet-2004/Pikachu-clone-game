#include "header.h"

int main(){
    //playMusic();
    MoveWindow(0, 0);
    ShowConsoleCursor(false);

    PlayerState player;
    SaveState save;
    BoardState board;
    board.row = 4;
    board.col = 6;

    int count = 24, lvl = 1, lvlcap[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, score = 0;
    int curX = 1, curY = 1, x1 = 0, y1 = 0, x2 = 0, y2 = 0, line[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    int sugx1 = 0, sugx2 = 0, sugy1 = 0, sugy2 = 0;
    int menu = 1, mCurX = 1, playerid, mode = 0;
    time_t oriTime;
    bool nmCheck = false, **nightmare, succlog = false, eot = false, cont = false, segg = false;
    while(true){
        while ((menu > 0 && menu < 4) || menu == 6)
        {
            while(!succlog)
                login(player, mCurX, menu, playerid, succlog, save);
            ClearScreen();
            generateMenu(player, board, menu, mCurX, nmCheck, mode, succlog, save, cont);
        }
        if (menu == 0)
            break;
        else if (menu == 4)
        {
            ClearScreen();
            if(save.mode && cont)
            {
                loadGame(save, playerid, board, mode, oriTime, lvl, lvlcap, count, score);
                cont = false;
            }
            else
            {
                resetGame(board, count, lvl, lvlcap, curX, curY);
                generateBoard(board);
                while(!checkLegalMove(board))
                    resetBoard(board);
                oriTime = time(0) - min(lvl, 100);
            }
            generateArt(board);
            if (nmCheck)
                generateNightmare(board, nightmare);
            menu++;
        }
        while (menu == 5)
        {
            while(menu == 5 && !(x1 && y1 && x2 && y2))
            {
                cursor(0, 0);
                cout << "\t\t\tLevel: " << lvl << "\t\t\t\t" << endl;
                showBoard(board, curX, curY, x1, y1, nightmare, nmCheck);
                showTime(oriTime, menu, eot, score);
                if(kbhit())
                    keyboardSelect(board, curX, curY, x1, y1, x2, y2, menu, segg);
            }
            if (menu == 5)
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
                    calculateScore(score, mode, oriTime, lvl);
                    updateLB(player, playerid, mode, score);
                    cursor(0, 1);
                    curX = board.row + 2, curY = board.col + 2;
                    showBoard(board, curX, curY, x1, y1, nightmare, nmCheck);
                    cout << endl << endl << endl << "Victory royale!!!!" << endl << "Your score: " << score << endl;
                    string ch ="";
                    while (ch != "Y" && ch != "N" && ch != "y" && ch != "n")
                    {
                        cout << "Continue(Y/N)?: ";
                        getline(cin, ch);
                    }
                    if(ch == "Y" || ch == "y")
                    {
                        lvl++;
                        deleteMem(board);
                        deleteArt(board);
                        if (nmCheck)
                            deleteNightmare(board, nightmare);
                        menu = 4;
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
                        createGame(playerid);
                        loadGame(save, playerid, board, mode, oriTime, lvl, lvlcap, count, score);
                        menu = 1;
                    }
                }
            }
            else
            {
                if(!eot)
                {
                    saveGame(save, playerid, board, mode, oriTime, lvl, lvlcap[0], count, score);
                    score = 0;
                }
                deleteMem(board);
                deleteArt(board);
                if (nmCheck)
                {
                    deleteNightmare(board, nightmare);
                    nmCheck = false;
                }
                if(eot)
                {
                    createGame(playerid);
                    eot = false;
                    loadGame(save, playerid, board, mode, oriTime, lvl, lvlcap, count, score);
                }
                x1 = 0;
                x2 = 0;
            }
        }
    }
    return 0;
}
