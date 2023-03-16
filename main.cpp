#include "header.h"

int main(){
    int m, n, **a;
    generateBoard(m, n, a);
    while(!checkLegalMove(m, n, a)){
        resetBoard(m, n, a);
    }
    showBoard(m, n, a);
    int x1, x2, y1, y2;
    int count = m * n;
    while(count != 0){
        cout << "Please input the index of the first tile: ";
        cin >> x1 >> y1;
        cout << "Please input the index of the second tile: ";
        cin >> x2 >> y2;
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