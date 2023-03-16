#include "header.h"
#include <stdlib.h>
int main(){
    int m, n, **a;
    generateBoard(m, n, a);
    while(!checkLegalMove(m, n, a)){
        resetBoard(m, n, a);
    }
    system("cls");
    showBoard(m, n, a);
    int x1, x2, y1, y2;
    int count = m * n;
    while(count != 0){
        while(true){    
            cout << "Please input the x index of the first tile: ";
            cin >> x1;
            cout << "Please input the y index of the first tile: ";
            cin >> y1;
            cout << "Please input the x index of the second tile: ";
            cin >> x2;
            cout << "Please input the y index of the second tile: ";
            cin >> y2;
            if (x1 > m || x1 <= 0 || x2 > m || x2 <= 0 || y1 > n || y1 <= 0 || y2 > n || y2 <= 0){
                cout << "Invalid input. Please input again!" << endl;
            }
            else
                break;
        }
        system("cls");
        if (findPath(m, n, a, x1, x2, y1, y2)){
            a[x1][y1] = 0;
            a[x2][y2] = 0;
            count -= 2;
        }
        while(!checkLegalMove(m, n, a) && count != 0){
            resetBoard(m, n, a);
        }
        showBoard(m, n, a);
    }
    if (count == 0) cout << "Victory royale!!!!" << endl;
    deleteMem(m, n, a);
    return 0;
}