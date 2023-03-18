#include "menu.h"

void generateMenu(int &m, int &n, int &mSelect, int &mCurX, int &mCurY, bool &nmCheck)
{
    printMenu(m, n, mSelect, mCurX, mCurY);
    int c = getch(), ch;
    if(c == 224)
        switch(ch = getch())
        {
            case KEY_UP:
            {
                if((mSelect == 2 || mSelect == 1) && mCurX > 1)
                    mCurX--;
                else if (mSelect == 1)
                    mCurX = 2;
                else if (mSelect == 2)
                    mCurX = 5;
                else if (mSelect == 3)
                {
                    if(mCurY == 1)
                        mCurY = 2;
                    else
                        mCurY = 1;
                    break;
                }
                break;
            }
            case KEY_DOWN:
            {
                if((mSelect == 2 && mCurX < 5) || (mSelect == 1 && mCurX < 2))
                    mCurX++;
                else if (mSelect == 1 || mSelect == 2)
                    mCurX = 1;
                else if (mSelect == 3)
                {
                    if(mCurY == 2)
                        mCurY = 1;
                    else
                        mCurY = 2;
                    break;
                }
                break;
            }
            case KEY_LEFT:
            {
                if (mSelect == 3)
                {
                    if (mCurY == 1 && m > 4)
                        m--;
                    else if (mCurY == 2 && n > 6)
                        n--;
                }
                break;
            }
            case KEY_RIGHT:
            {
                if (mSelect == 3)
                {
                    if (mCurY == 1 && m < 10)
                        m++;
                    else if (mCurY == 2 && n < 10)
                        n++;
                }
                break;
            }
        }
    else if (c == KEY_SPACE)
    {
        if (mSelect == 1)
        {
            if (mCurX == 1)
                mSelect++;
            else
                mSelect = 0;
        }
        else if (mSelect == 2)
        {
            switch (mCurX)
            {
                case 1:
                {
                    m = 4;
                    n = 6;
                    mSelect = 4;
                    mCurX = 1;
                    break;
                }
                case 2:
                {
                    m = 6;
                    n = 8;
                    mSelect = 4;
                    mCurX = 1;
                    break;
                }
                case 3:
                {
                    m = 10;
                    n = 10;
                    mSelect = 4;
                    mCurX = 1;
                    break;
                }
                case 4:
                {
                    m = 10;
                    n = 10;
                    mSelect = 4;
                    mCurX = 1;
                    nmCheck = true;
                    break;
                }
                case 5:
                {
                    mSelect++;
                    break;
                }
            }
        }
        else if (mSelect == 3)
        {
            if (m * n % 2 == 0)
            {
                mCurY = 1;
                mSelect++;
            }
        }
    }
    else if (c == KEY_ESCAPE)
    {
        mSelect = 1;
        mCurX = 1;
        mCurY = 1;
        m = 4;
        n = 6;
    }
}

void printMenu(int m, int n, int mSelect, int mCurX, int mCurY)
{
    cout << endl << "\t\tPikachuchu" << endl << endl;
    switch (mSelect)
    {
        case 1:
        {
            if (mCurX == 1)
            {
                cout << "\t\t< START >" << endl;
                cout << "\t\t  QUIT" << endl;
            }
            else if (mCurX == 2)
            {
                cout << "\t\t  START" << endl;
                cout << "\t\t< QUIT >" << endl;
            }
            break;
        }
        case 2:
        {
            switch (mCurX)
            {
                case 1:
                {
                    cout << "\t\t< Easy >" << endl;
                    cout << "\t\t  Medium" << endl;
                    cout << "\t\t  Hard" << endl;
                    cout << "\t\t  Nightmare" << endl;
                    cout << "\t\t  Custom" << endl;
                    break;
                }
                case 2:
                {
                    cout << "\t\t  Easy" << endl;
                    cout << "\t\t< Medium >" << endl;
                    cout << "\t\t  Hard" << endl;
                    cout << "\t\t  Nightmare" << endl;
                    cout << "\t\t  Custom" << endl;
                    break;
                }
                case 3:
                {
                    cout << "\t\t  Easy" << endl;
                    cout << "\t\t  Medium" << endl;
                    cout << "\t\t< Hard >" << endl;
                    cout << "\t\t  Nightmare" << endl;
                    cout << "\t\t  Custom" << endl;
                    break;
                }
                case 4:
                {
                    cout << "\t\t  Easy" << endl;
                    cout << "\t\t  Medium" << endl;
                    cout << "\t\t  Hard" << endl;
                    cout << "\t\t< Nightmare >" << endl;
                    cout << "\t\t  Custom" << endl;
                    break;
                }
                case 5:
                {
                    cout << "\t\t  Easy" << endl;
                    cout << "\t\t  Medium" << endl;
                    cout << "\t\t  Hard" << endl;
                    cout << "\t\t  Nightmare" << endl;
                    cout << "\t\t< Custom >" << endl;
                    break;
                }
            }
            break;
        }
        case 3:
        {
            switch (mCurY)
            {
                case 1:
                {
                    cout << "Choose the number of rows:    < " << m << " >" << endl;
                    cout << "Choose the number of columns:   " << n << "  " << endl;
                    break;
                }
                case 2:
                {
                    cout << "Choose the number of rows:      " << m << "  " << endl;
                    cout << "Choose the number of columns: < " << n << " >" << endl;
                    break;
                }
            }
        }
    }
}
