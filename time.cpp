#include "time.h"

void showTime(time_t oriTime, int &mSelect)
{
    time_t nowTime = time(0);
    int diff = difftime(nowTime, oriTime);
    if (120 - diff < 0)
        endGame(mSelect);
    for (int i = 120 - diff; i > 0; i--)
        cout << "|";
    for (int i = diff; i > 0; i--)
        cout << " ";
}

void endGame(int &mSelect)
{
    cout << "Time end!";
    getch();
    mSelect = 1;
}
