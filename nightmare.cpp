#include "nightmare.h"

void deleteNightmare(int m, int n, bool **&nightmare)
{
    for (int i = 0; i < m + 2; i++)
        delete[] nightmare[i];
    delete[] nightmare;
}

void generateNightmare(int m, int n, bool **&nightmare)
{
    nightmare = new bool*[m + 2];
    for (int i = 0; i < m + 2; i++)
        nightmare[i] = new bool[n + 2];

    for (int i = 0; i < m + 2; i++)
        for (int j = 0; j < n + 2; j++)
            nightmare[i][j] = false;
}

void resetNightmare(int m, int n, bool **nightmare)
{
    srand(time(0));
    for (int i = 0; i < m + 2; i++)
        for (int j = 0; j < n + 2; j++)
            if ((rand() % 50) % 2 == 0)
                nightmare[i][j] = true;
            else
                nightmare[i][j] = false;
}
