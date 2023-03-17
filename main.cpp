#include "header.h"
#include <stdlib.h>

int main(){
    int m, n, **a, lvl = 1, lvlcap[] = {1, 8, 9, 9};
    int curX = 1, curY = 1, x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    generateBoard(m, n, a, true);
    while(!checkLegalMove(m, n, a)){
        resetBoard(m, n, a);
    }
    int count = m * n;
    system("cls");
    while(count != 0){
        while(!(x1 && y1 && x2 && y2))
        {
            cursor(0, 0);
            cout << "\t\t Level: " << lvl << "\t\t\t\t" << endl;
            showBoard(m, n, a, curX, curY, x1, y1);
            keyboardSelect(m, n, a, curX, curY, x1, y1, x2, y2);
        }
        if (findPath(m, n, a, x1, x2, y1, y2)){
            a[x1][y1] = 0;
            a[x2][y2] = 0;
            count -= 2;
            levelCheck(m, n, a, x1, y1, x2, y2, lvl, lvlcap);
            if (count)
                while (!checkLegalMove(m, n, a))
                    resetBoard(m, n, a);
        }
        x1 = 0;
        y1 = 0;
        x2 = 0;
        y2 = 0;
        if (!count)
		{
		    cursor(0, 1);
		    curX = 0, curY = 0;
		    showBoard(m, n, a, curX, curY, x1, y1);
			cout << "Victory royale!!!!" << endl << endl;
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

				count = m * n;
				generateBoard(m, n, a, false);
				while(!checkLegalMove(m, n, a))
		        	resetBoard(m, n, a);
                curX = 1;
                curY = 1;
                lvlcap[0] = 1;
                system("cls");
			}
			else
				break;
		}
    }
    deleteMem(m, n, a);
    return 0;
}
