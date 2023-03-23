#include "gameLogic.h"

bool findPath(BoardState a, int x1, int x2, int y1, int y2, int line[][2]){
    if (a.board[x1][y1] != a.board[x2][y2] || a.board[x1][y1] == 0 || a.board[x2][y2] == 0) return false;

    //Tạo graph
    int **graph;
    graph = new int*[a.row + 2];
    for (int i = 0; i < a.row + 2; i++)
        graph[i] = new int [a.col + 2];

	for (int i = 0; i < a.row + 2; i++)
	{
		for (int j = 0; j < a.col + 2; j++)
		{
			graph[i][j] = (a.board[i][j] != 0);
		}
	}
    pair<int, int> start = {x1, y1};
    pair<int, int> end = {x2, y2};

    //BFS
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
    deque<pair<int, int>> q;
    //vector<vector<pair<int, int>>> trace(m + 2, vector<pair<int, int>>(n + 2, make_pair(-1, -1)));
    pair <int, int> **trace;
    trace = new pair<int, int> * [a.row + 2];
    for (int i = 0; i < a.row + 2; i++)
        trace[i] = new pair<int, int> [a.col + 2];

    for (int i = 0; i < a.row + 2; i++)
        for (int j = 0; j < a.col + 2; j++)
            trace[i][j] = make_pair(-1, -1);

    q.push_back(end);
    trace[end.first][end.second] = make_pair(-2, -2);
	graph[start.first][start.second] = 0;
	graph[end.first][end.second] = 0;
    while (!q.empty()) {
		auto u = q.front();
		q.pop_front();
		if (u == start) break;
		for (int i = 0; i < 4; ++i) {
			int x = u.first + dx[i];
			int y = u.second + dy[i];
			while (x >= 0 && x < a.row + 2 && y >= 0 && y < a.col + 2 && graph[x][y] == 0) {
				if (trace[x][y].first == -1) {
					trace[x][y] = u;
					q.push_back({ x, y });
				}
				x += dx[i];
				y += dy[i];
			}
		}
	}

    //Truy vết ngược về
    vector<pair<int, int>> route;
	if (trace[start.first][start.second].first != -1) {
        int q = 0;
		while (start.first != -2) {
			route.push_back({ start.first - 1, start.second - 1 });
			if (q < 4)
            {
                line[q][0] = start.first;
                line[q][1] = start.second;
                q++;
            }
			start = trace[start.first][start.second];
		}
	}

    for(int i = 0; i < a.row + 2; i++)
        delete[] graph[i];
    delete[] graph;

    for(int i = 0; i < a.row + 2; i++)
        delete[] trace[i];
    delete[] trace;

    return route.size() >= 2 &&  route.size() <= 4;
}

bool checkLegalMove(BoardState a){
    vector<pair <int, int>> check[25];
    for (int i = 1; i <= a.row; i++){
        for (int j = 1; j <= a.col; j++){

            if (a.board[i][j] != 0)
                check[a.board[i][j] - (int)'A'].push_back(make_pair(i, j));
        }
    }

    for (int i = 0; i < 25; i++)
        if (!check[i].empty())
            for (int j = 0; j < check[i].size() - 1; j++)
                for (int _j = j + 1; _j < check[i].size(); _j++)
                {
                    int path[4][2];
                    if (findPath(a, check[i][j].first, check[i][_j].first, check[i][j].second, check[i][_j].second, path))
                        return true;
                }
    return false;
}


///////////////////////////////////////////////////////////////////

void levelCheck(BoardState a, int x1, int y1, int x2, int y2, int lvl, int lvlcap[])
{
    while(true)
    {
        if (lvlcap[lvlcap[0]])
        {
            switch(lvlcap[lvlcap[0]])
            {
                case 1:
                {
                    goStand(a, x1, y1, x2, y2);
                    break;
                }
                case 2:
                {
                    goUp(a, x1, y1, x2, y2);
                    break;
                }
                case 3:
                {
                    goDown(a, x1, y1, x2, y2);
                    break;
                }
                case 4:
                {
                    goLeft(a, x1, y1, x2, y2);
                    break;
                }
                case 5:
                {
                    goRight(a, x1, y1, x2, y2);
                    break;
                }
                case 6:
                {
                    goSLR(a, x1, y1, x2, y2);
                    break;
                }
                case 7:
                {
                    goMLR(a, x1, y1, x2, y2);
                    break;
                }
                case 8:
                {
                    goSUD(a, x1, y1, x2, y2);
                    break;
                }
                case 9:
                {
                    goMUD(a, x1, y1, x2, y2);
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

void goStand(BoardState a, int x1, int y1, int x2, int y2)
{
	//Do nothing...
	int boring = 0;
}

void goUp(BoardState a, int x1, int y1, int x2, int y2)
{
	for(int i = x1 + 1, u = x1; i <= a.row; i++)
		if(a.board[i][y1])
			for(; u < i; u++)
				if(!a.board[u][y1])
				{
					swap(a.board[i][y1], a.board[u][y1]);
					u++;
					break;
				}
	for(int i = x2 + 1, u = x2; i <= a.row; i++)
		if(a.board[i][y2])
			for(; u < i; u++)
				if(!a.board[u][y2])
				{
					swap(a.board[i][y2], a.board[u][y2]);
					u++;
					break;
				}
}

void goDown(BoardState a, int x1, int y1, int x2, int y2)
{
	for(int i = x1 - 1, u = x1; i > 0; i--)
		if(a.board[i][y1])
			for(; u > i; u--)
				if(!a.board[u][y1])
				{
					swap(a.board[i][y1], a.board[u][y1]);
					u--;
					break;
				}

	for(int i = x2 - 1, u = x2; i > 0; i--)
		if(a.board[i][y2])
			for(; u > i; u--)
				if(!a.board[u][y2])
				{
					swap(a.board[i][y2], a.board[u][y2]);
					u--;
					break;
				}
}

void goLeft(BoardState a, int x1, int y1, int x2, int y2)
{
	for(int i = y1 + 1, u = y1; i <= a.col; i++)
		if(a.board[x1][i])
			for(; u < i; u++)
				if(!a.board[x1][u])
				{
					swap(a.board[x1][i], a.board[x1][u]);
					u++;
					break;
				}

	for(int i = y2 + 1, u = y2; i <= a.col; i++)
		if(a.board[x2][i])
			for(; u < i; u++)
				if(!a.board[x2][u])
				{
					swap(a.board[x2][i], a.board[x2][u]);
					u++;
					break;
				}
}

void goRight(BoardState a, int x1, int y1, int x2, int y2)
{
	for(int i = y1 - 1, u = y1; i > 0; i--)
		if(a.board[x1][i])
			for(; u > i; u--)
				if(!a.board[x1][u])
				{
					swap(a.board[x1][i], a.board[x1][u]);
					u--;
					break;
				}
	for(int i = y2 - 1, u = y2; i > 0; i--)
		if(a.board[x2][i])
			for(; u > i; u--)
				if(!a.board[x2][u])
				{
					swap(a.board[x2][i], a.board[x2][u]);
					u--;
					break;
				}
}

void goSLR(BoardState a, int x1, int y1, int x2, int y2)
{
	if (y1 <= a.col / 2)
	{
	    for(int i = y1 + 1, u = y1; i <= a.col / 2; i++)
        {
            if(a.board[x1][i])
            {
                for(; u < i; u++)
                {
                    if(!a.board[x1][u])
                    {
                        swap(a.board[x1][i], a.board[x1][u]);
                        u++;
                        break;
                    }
                }
            }
        }
	}
	else
    {
        for(int i = y1 - 1, u = y1; i > a.col / 2; i--)
        {
            if(a.board[x1][i])
            {
                for(; u > i; u--)
                {
                    if(!a.board[x1][u])
                    {
                        swap(a.board[x1][i], a.board[x1][u]);
                        u--;
                        break;
                    }
                }
            }
        }
    }
    if (y2 <= a.col / 2)
	{
	    for(int i = y2 + 1, u = y2; i <= a.col / 2; i++)
        {
            if(a.board[x2][i])
            {
                for(; u < i; u++)
                {
                    if(!a.board[x2][u])
                    {
                        swap(a.board[x2][i], a.board[x2][u]);
                        u++;
                        break;
                    }
                }
            }
        }
	}
	else
    {
        for(int i = y2 - 1, u = y2; i > a.col / 2; i--)
        {
            if(a.board[x2][i])
            {
                for(; u > i; u--)
                {
                    if(!a.board[x2][u])
                    {
                        swap(a.board[x2][i], a.board[x2][u]);
                        u--;
                        break;
                    }
                }
            }
        }
    }
}

void goMLR(BoardState a, int x1, int y1, int x2, int y2)
{
	if (y1 > a.col / 2)
	{
	    for(int i = y1 + 1, u = y1; i <= a.col; i++)
        {
            if(a.board[x1][i])
            {
                for(; u < i; u++)
                {
                    if(!a.board[x1][u])
                    {
                        swap(a.board[x1][i], a.board[x1][u]);
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
            if(a.board[x1][i])
            {
                for(; u > i; u--)
                {
                    if(!a.board[x1][u])
                    {
                        swap(a.board[x1][i], a.board[x1][u]);
                        u--;
                        break;
                    }
                }
            }
        }
    }
    if (y2 > a.col / 2)
	{
	    for(int i = y2 + 1, u = y2; i <= a.col; i++)
        {
            if(a.board[x2][i])
            {
                for(; u < i; u++)
                {
                    if(!a.board[x2][u])
                    {
                        swap(a.board[x2][i], a.board[x2][u]);
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
            if(a.board[x2][i])
            {
                for(; u > i; u--)
                {
                    if(!a.board[x2][u])
                    {
                        swap(a.board[x2][i], a.board[x2][u]);
                        u--;
                        break;
                    }
                }
            }
        }
    }
}

void goSUD(BoardState a, int x1, int y1, int x2, int y2)
{
	if (x1 <= a.row / 2)
    {
        for(int i = x1 + 1, u = x1; i <= a.row / 2; i++)
        {
            if(a.board[i][y1])
            {
                for(; u < i; u++)
                {
                    if(!a.board[u][y1])
                    {
                        swap(a.board[i][y1], a.board[u][y1]);
                        u++;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        for(int i = x1 - 1, u = x1; i > a.row / 2; i--)
        {
            if(a.board[i][y1])
            {
                for(; u > i; u--)
                {
                    if(!a.board[u][y1])
                    {
                        swap(a.board[i][y1], a.board[u][y1]);
                        u--;
                        break;
                    }
                }
            }
        }
    }
    if (x2 <= a.row / 2)
    {
        for(int i = x2 + 1, u = x2; i <= a.row / 2; i++)
        {
            if(a.board[i][y2])
            {
                for(; u < i; u++)
                {
                    if(!a.board[u][y2])
                    {
                        swap(a.board[i][y2], a.board[u][y2]);
                        u++;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        for(int i = x2 - 1, u = x2; i > a.row / 2; i--)
        {
            if(a.board[i][y2])
            {
                for(; u > i; u--)
                {
                    if(!a.board[u][y2])
                    {
                        swap(a.board[i][y2], a.board[u][y2]);
                        u--;
                        break;
                    }
                }
            }
        }
    }
}

void goMUD(BoardState a, int x1, int y1, int x2, int y2)
{
	if (x1 <= a.row / 2)
    {
        for(int i = x1 - 1, u = x1; i > 0; i--)
        {
            if(a.board[i][y1])
            {
                for(; u > i; u--)
                {
                    if(!a.board[u][y1])
                    {
                        swap(a.board[i][y1], a.board[u][y1]);
                        u--;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        for(int i = x1 + 1, u = x1; i <= a.row; i++)
        {
            if(a.board[i][y1])
            {
                for(; u < i; u++)
                {
                    if(!a.board[u][y1])
                    {
                        swap(a.board[i][y1], a.board[u][y1]);
                        u++;
                        break;
                    }
                }
            }
        }
    }
    if (x2 <= a.row / 2)
    {
        for(int i = x2 - 1, u = x2; i > 0; i--)
        {
            if(a.board[i][y2])
            {
                for(; u > i; u--)
                {
                    if(!a.board[u][y2])
                    {
                        swap(a.board[i][y2], a.board[u][y2]);
                        u--;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        for(int i = x2 + 1, u = x2; i <= a.row; i++)
        {
            if(a.board[i][y2])
            {
                for(; u < i; u++)
                {
                    if(!a.board[u][y2])
                    {
                        swap(a.board[i][y2], a.board[u][y2]);
                        u++;
                        break;
                    }
                }
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////
void deleteNightmare(BoardState a, bool **&nightmare)
{
    for (int i = 0; i < a.row + 2; i++)
        delete[] nightmare[i];
    delete[] nightmare;
}

void generateNightmare(BoardState a, bool **&nightmare)
{
    nightmare = new bool*[a.row + 2];
    for (int i = 0; i < a.row + 2; i++)
        nightmare[i] = new bool[a.col + 2];

    for (int i = 0; i < a.row + 2; i++)
        for (int j = 0; j < a.col + 2; j++)
            nightmare[i][j] = false;
}

void resetNightmare(BoardState a, bool **nightmare)
{
    srand(time(0));
    for (int i = 0; i < a.row + 2; i++)
        for (int j = 0; j < a.col + 2; j++)
            if ((rand() % 50) % 2 == 0)
                nightmare[i][j] = true;
            else
                nightmare[i][j] = false;
}
