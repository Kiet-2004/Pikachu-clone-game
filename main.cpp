#include "header.h"

int main(){
    //playMusic();
    MoveWindow(0, 0);
    ShowConsoleCursor(false);

    PlayerState player;
    BoardState board;
    LeaderBoard lb;
    loadLB(lb);

    int lvlcap[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    int FcurX = 1, FcurY = 1, curX = 1, curY = 1, x1 = 0, y1 = 0, x2 = 0, y2 = 0, line[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    int sugx1 = 0, sugx2 = 0, sugy1 = 0, sugy2 = 0;
    int menu = 1, mCurX = 1, playerid;
    time_t oriTime, suggtime = 0;
    bool nmCheck = false, **nightmare, succlog = false, eot = false, cont = false, resetcheck = false, newgame = false, endsugg = false;
    bool hint = false, choose_1 = false, choose_2 = false;
    while(true){
        while ((menu > 0 && menu < 4) || menu == 6)
        {
            while(!succlog)
                login(player, board, mCurX, menu, playerid, succlog, lvlcap, oriTime);
            ClearScreen();
            generateMenu(lb, player.mode, board.row, board.col, menu, mCurX, nmCheck, succlog, cont, player.lvl);
        }
        if (menu == 0)
            break;
        else if (menu == 4)
        {
            ClearScreen();
            if(cont)
            {
                loadGame(player, playerid, board, lvlcap, oriTime);
                checkLegalMove(board, sugx1, sugy1, sugx2, sugy2);
                cont = false;
            }
            else
            {
                resetGame(board, player.count, player.lvl, lvlcap, curX, curY, FcurX, FcurY);
                generateBoard(board);
                while(!checkLegalMove(board, sugx1, sugy1, sugx2, sugy2))
                    resetBoard(board);
                oriTime = time(0) - min(player.lvl, 100);
            }
            generateArt(board);
            if (nmCheck)
                generateNightmare(board, nightmare);
            menu++;
            newgame = true;
        }
        while (menu == 5)
        {
            while(menu == 5)
            {
                cursor(0, 0);
                SetColor(6);
                cout << "\t\t\tLevel: " << player.lvl << "\t\t\t\t" << endl;
                showBoard(board, player.lvl, curX, curY, FcurX, FcurY, x1, y1, x2, y2, nmCheck, nightmare, suggtime, endsugg, sugx1, sugy1, sugx2, sugy2, newgame, hint, choose_1, choose_2);
                showTime(player.timeleft, oriTime, menu, eot, player.score, suggtime, board, endsugg);
                if(kbhit())
                    keyboardSelect(board, curX, curY, x1, y1, x2, y2, menu, suggtime, oriTime, hint, choose_1, choose_2);
                if(choose_2)
                    break;
            }
            if (menu == 5)
            {
                if (findPath(board, x1, x2, y1, y2, line)){
                    suggtime = 0;
                    endsugg = true;
                    board.board[x1][y1] = 0;
                    board.board[x2][y2] = 0;
                    player.count -= 2;
                    drawLine(line);
                    Sleep(150);
                    clearLine(line, board);
                    levelCheck(board, x1, y1, x2, y2, player.lvl, lvlcap);
                    if (player.count)
                        while (!checkLegalMove(board, sugx1, sugy1, sugx2, sugy2))
                        {
                            resetBoard(board);
                            resetcheck = true;
                        }
                    if(resetcheck)
                    {
                        bool **temp;
                        for(int i = 1; i <= board.row; i++)
                            for(int u = 1; u <= board.col; u++)
                                if(board.board[i][u])
                                    printCell(board.board[i][u] % 7 + 9, board.board[i][u], i, u, 0, temp);
                        oriTime -= 10;
                        resetcheck = false;
                    }
                }
                if (nmCheck)
                    resetNightmare(board, nightmare);
                if (!player.count)
                {
                    calculateScore(player);
                    cursor(0, 1);
                    curX = board.row + 2, curY = board.col + 2;
                    FcurX = curX, FcurY = curY;
                    showBoard(board, player.lvl, curX, curY, FcurX, FcurY, x1, y1, x2, y2, nmCheck, nightmare, suggtime, endsugg, sugx1, sugy1, sugx2, sugy2, newgame, hint, choose_1, choose_2);
                    SetColor(6);
                    gotoxy(12, (board.col + 2) * 5 + 5);
                    cout << "Victory royale!!!!";
                    gotoxy(13, (board.col + 2) * 5 + 5);
                    cout << "Your score: " << player.score << endl;
                    string ch ="";
                    while (ch != "Y" && ch != "N" && ch != "y" && ch != "n")
                    {
                        gotoxy(14, (board.col + 2) * 5 + 5);
                        cout << "Continue(Y/N)?:                     ";
                        gotoxy(14, (board.col + 2) * 5 + 21);
                        getline(cin, ch);
                    }
                    if(ch == "Y" || ch == "y")
                    {
                        player.lvl++;
                        deleteMem(board);
                        deleteArt(board);
                        if (nmCheck)
                            deleteNightmare(board, nightmare);
                        menu = 4;
                    }
                    else
                    {
                        updateLB(lb, player);
                        deleteMem(board);
                        deleteArt(board);
                        if (nmCheck)
                        {
                            deleteNightmare(board, nightmare);
                            nmCheck = false;
                        }
                        eraseGame(player, board, lvlcap);
                        saveGame(player, playerid, board);
                        for (int i = 1; i < 10; i++)
                                lvlcap[i] = 0;
                        menu = 1;
                    }
                }
            }
            else
            {
                suggtime = 0;
                if(eot){
                    updateLB(lb, player);
                    eraseGame(player, board, lvlcap);
                    eot = false;
                }
                if(player.mode == 4)
                    eraseGame(player, board, lvlcap);
                saveGame(player, playerid, board);
                deleteMem(board);
                deleteArt(board);
                if (nmCheck)
                {
                    deleteNightmare(board, nightmare);
                    nmCheck = false;
                }
                for (int i = 1; i < 10; i++)
                    lvlcap[i] = 0;
                x1 = 0;
                x2 = 0;
                y1 = 0;
                y2 = 0;
            }
        }
    }
    return 0;
}
