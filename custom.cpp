/*
MLR = Merge Left-Right
MUD = Merge Up-Down
SLR = Split Left-Right
SUP = Split Up-Down
*/

#include "custom.h"

void levelCheck(int m, int n, int **a, int x1, int y1, int x2, int y2, int lvl, int lvlcap[])
{
    while(true)
    {
        if (lvlcap[lvlcap[0]])
        {
            switch(lvlcap[lvlcap[0]])
            {
                case 1:
                {
                    goStand(m, n, a, x1, y1, x2, y2);
                    break;
                }
                case 2:
                {
                    goUp(m, n, a, x1, y1, x2, y2);
                    break;
                }
                case 3:
                {
                    goDown(m, n, a, x1, y1, x2, y2);
                    break;
                }
                case 4:
                {
                    goLeft(m, n, a, x1, y1, x2, y2);
                    break;
                }
                case 5:
                {
                    goRight(m, n, a, x1, y1, x2, y2);
                    break;
                }
                case 6:
                {
                    goSLR(m, n, a, x1, y1, x2, y2);
                    break;
                }
                case 7:
                {
                    goMLR(m, n, a, x1, y1, x2, y2);
                    break;
                }
                case 8:
                {
                    goSUD(m, n, a, x1, y1, x2, y2);
                    break;
                }
                case 9:
                {
                    goMUD(m, n, a, x1, y1, x2, y2);
                    break;
                }
            }
            if(lvlcap[0] == 3)
                lvlcap[0] = 1;
            else
                lvlcap[0]++;
            break;
        }
        else
            lvlcap[0]++;
    }
}

void goStand(int m, int n, int **a, int x1, int y1, int x2, int y2)
{
	//Do nothing...
	int boring = 0;
}

void goUp(int m, int n, int **a, int x1, int y1, int x2, int y2)
{
	for(int i = x1 + 1, u = x1; i <= m; i++)
		if(a[i][y1])
			for(; u < i; u++)
				if(!a[u][y1])
				{
					swap(a[i][y1], a[u][y1]);
					u++;
					break;
				}
	for(int i = x2 + 1, u = x2; i <= m; i++)
		if(a[i][y2])
			for(; u < i; u++)
				if(!a[u][y2])
				{
					swap(a[i][y2], a[u][y2]);
					u++;
					break;
				}
}

void goDown(int m, int n, int **a, int x1, int y1, int x2, int y2)
{
	for(int i = x1 - 1, u = x1; i > 0; i--)
		if(a[i][y1])
			for(; u > i; u--)
				if(!a[u][y1])
				{
					swap(a[i][y1], a[u][y1]);
					u--;
					break;
				}
	for(int i = x2 - 1, u = x2; i > 0; i--)
		if(a[i][y2])
			for(; u > i; u--)
				if(!a[u][y2])
				{
					swap(a[i][y2], a[u][y2]);
					u--;
					break;
				}
}

void goLeft(int m, int n, int **a, int x1, int y1, int x2, int y2)
{
	for(int i = y1 + 1, u = y1; i <= n; i++)
		if(a[x1][i])
			for(; u < i; u++)
				if(!a[x1][u])
				{
					swap(a[x1][i], a[x1][u]);
					u++;
					break;
				}
	for(int i = y2 + 1, u = y2; i <= n; i++)
		if(a[x2][i])
			for(; u < i; u++)
				if(!a[x2][u])
				{
					swap(a[x2][i], a[x2][u]);
					u++;
					break;
				}
}

void goRight(int m, int n, int **a, int x1, int y1, int x2, int y2)
{
	for(int i = y1 - 1, u = y1; i > 0; i--)
		if(a[x1][i])
			for(; u > i; u--)
				if(!a[x1][u])
				{
					swap(a[x1][i], a[x1][u]);
					u--;
					break;
				}
	for(int i = y2 - 1, u = y2; i > 0; i--)
		if(a[x2][i])
			for(; u > i; u--)
				if(!a[x2][u])
				{
					swap(a[x2][i], a[x2][u]);
					u--;
					break;
				}
}

void goSLR(int m, int n, int **a, int x1, int y1, int x2, int y2)
{
	if (y1 <= n/2)
	{
	    for(int i = y1 + 1, u = y1; i <= n/2; i++)
        {
            if(a[x1][i])
            {
                for(; u < i; u++)
                {
                    if(!a[x1][u])
                    {
                        swap(a[x1][i], a[x1][u]);
                        u++;
                        break;
                    }
                }
            }
        }
	}
	else
    {
        for(int i = y1 - 1, u = y1; i > n/2; i--)
        {
            if(a[x1][i])
            {
                for(; u > i; u--)
                {
                    if(!a[x1][u])
                    {
                        swap(a[x1][i], a[x1][u]);
                        u--;
                        break;
                    }
                }
            }
        }
    }
    if (y2 <= n/2)
	{
	    for(int i = y2 + 1, u = y2; i <= n/2; i++)
        {
            if(a[x2][i])
            {
                for(; u < i; u++)
                {
                    if(!a[x2][u])
                    {
                        swap(a[x2][i], a[x2][u]);
                        u++;
                        break;
                    }
                }
            }
        }
	}
	else
    {
        for(int i = y2 - 1, u = y2; i > n/2; i--)
        {
            if(a[x2][i])
            {
                for(; u > i; u--)
                {
                    if(!a[x2][u])
                    {
                        swap(a[x2][i], a[x2][u]);
                        u--;
                        break;
                    }
                }
            }
        }
    }
}

void goMLR(int m, int n, int **a, int x1, int y1, int x2, int y2)
{
	if (y1 > n/2)
	{
	    for(int i = y1 + 1, u = y1; i <= n; i++)
        {
            if(a[x1][i])
            {
                for(; u < i; u++)
                {
                    if(!a[x1][u])
                    {
                        swap(a[x1][i], a[x1][u]);
                        u++;
                        break;
                    }
                }
            }
        }
	}
	else
    {
        for(int i = y1 - 1, u = y1; i > 0; i--)
        {
            if(a[x1][i])
            {
                for(; u > i; u--)
                {
                    if(!a[x1][u])
                    {
                        swap(a[x1][i], a[x1][u]);
                        u--;
                        break;
                    }
                }
            }
        }
    }
    if (y2 > n/2)
	{
	    for(int i = y2 + 1, u = y2; i <= n; i++)
        {
            if(a[x2][i])
            {
                for(; u < i; u++)
                {
                    if(!a[x2][u])
                    {
                        swap(a[x2][i], a[x2][u]);
                        u++;
                        break;
                    }
                }
            }
        }
	}
	else
    {
        for(int i = y2 - 1, u = y2; i > 0; i--)
        {
            if(a[x2][i])
            {
                for(; u > i; u--)
                {
                    if(!a[x2][u])
                    {
                        swap(a[x2][i], a[x2][u]);
                        u--;
                        break;
                    }
                }
            }
        }
    }
}

void goSUD(int m, int n, int **a, int x1, int y1, int x2, int y2)
{
	if (x1 <= m/2)
    {
        for(int i = x1 + 1, u = x1; i <= m/2; i++)
        {
            if(a[i][y1])
            {
                for(; u < i; u++)
                {
                    if(!a[u][y1])
                    {
                        swap(a[i][y1], a[u][y1]);
                        u++;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        for(int i = x1 - 1, u = x1; i > m/2; i--)
        {
            if(a[i][y1])
            {
                for(; u > i; u--)
                {
                    if(!a[u][y1])
                    {
                        swap(a[i][y1], a[u][y1]);
                        u--;
                        break;
                    }
                }
            }
        }
    }
    if (x2 <= m/2)
    {
        for(int i = x2 + 1, u = x2; i <= m/2; i++)
        {
            if(a[i][y2])
            {
                for(; u < i; u++)
                {
                    if(!a[u][y2])
                    {
                        swap(a[i][y2], a[u][y2]);
                        u++;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        for(int i = x2 - 1, u = x2; i > m/2; i--)
        {
            if(a[i][y2])
            {
                for(; u > i; u--)
                {
                    if(!a[u][y2])
                    {
                        swap(a[i][y2], a[u][y2]);
                        u--;
                        break;
                    }
                }
            }
        }
    }
}

void goMUD(int m, int n, int **a, int x1, int y1, int x2, int y2)
{
	if (x1 <= m/2)
    {
        for(int i = x1 - 1, u = x1; i > 0; i--)
        {
            if(a[i][y1])
            {
                for(; u > i; u--)
                {
                    if(!a[u][y1])
                    {
                        swap(a[i][y1], a[u][y1]);
                        u--;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        for(int i = x1 + 1, u = x1; i <= m; i++)
        {
            if(a[i][y1])
            {
                for(; u < i; u++)
                {
                    if(!a[u][y1])
                    {
                        swap(a[i][y1], a[u][y1]);
                        u++;
                        break;
                    }
                }
            }
        }
    }
    if (x2 <= m/2)
    {
        for(int i = x2 - 1, u = x2; i > 0; i--)
        {
            if(a[i][y2])
            {
                for(; u > i; u--)
                {
                    if(!a[u][y2])
                    {
                        swap(a[i][y2], a[u][y2]);
                        u--;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        for(int i = x2 + 1, u = x2; i <= m; i++)
        {
            if(a[i][y2])
            {
                for(; u < i; u++)
                {
                    if(!a[u][y2])
                    {
                        swap(a[i][y2], a[u][y2]);
                        u++;
                        break;
                    }
                }
            }
        }
    }
}
