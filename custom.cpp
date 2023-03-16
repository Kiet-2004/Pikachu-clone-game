/*
MLR = Merge Left-Right
MUD = Merge Up-Down
SLR = Split Left-Right
SUP = Split Up-Down
*/

#include "custom.h"

void levelCheck(int m, int n, int **a, int x1, int y1, int x2, int y2, int lvl)
{
	switch(lvl)
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

void goRight(int m, int n, int **a, int x1, int y1, int x2, int y2)
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

void goSLR(int m, int n, int **a, int x1, int y1, int x2, int y2)
{
	//Do nothing...
	int boring = 0;	
}

void goMLR(int m, int n, int **a, int x1, int y1, int x2, int y2)
{
	//Do nothing...
	int boring = 0;	
}

void goSUD(int m, int n, int **a, int x1, int y1, int x2, int y2)
{
	//Do nothing...
	int boring = 0;	
}

void goMUD(int m, int n, int **a, int x1, int y1, int x2, int y2)
{
	//Do nothing...
	int boring = 0;	
}
