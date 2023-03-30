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
			route.push_back({ start.first, start.second});
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

bool checkLegalMove(BoardState a, int &sugx1, int &sugy1, int &sugx2, int &sugy2){
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
                    {
                        sugx1 = check[i][j].first;
                        sugy1 = check[i][j].second;
                        sugx2 = check[i][_j].first;
                        sugy2 = check[i][_j].second;
                        return true;
                    }
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
                case 2:
                {
                    goUp(a, x1, y1, a.row);
                    goUp(a, x2, y2, a.row);
                    break;
                }
                case 3:
                {
                    goDown(a, x1, y1, 0);
                    goDown(a, x2, y2, 0);
                    break;
                }
                case 4:
                {
                    goLeft(a, x1, y1, a.col);
                    goLeft(a, x2, y2, a.col);
                    break;
                }
                case 5:
                {
                    goRight(a, x1, y1, 0);
                    goRight(a, x2, y2, 0);
                    break;
                }
                case 6:
                {
                    if(y1 <= a.col/2)
                        goLeft(a, x1, y1, a.col/2);
                    else
                        goRight(a, x1, y1, a.col/2);
                    if(y2 <= a.col/2)
                        goLeft(a, x2, y2, a.col/2);
                    else
                        goRight(a, x2, y2, a.col/2);
                    break;
                }
                case 7:
                {
                    if(y1 <= a.col/2)
                        goRight(a, x1, y1, 0);
                    else
                        goLeft(a, x1, y1, a.col);
                    if(y2 <= a.col/2)
                        goRight(a, x2, y2, 0);
                    else
                        goLeft(a, x2, y2, a.col);
                    break;
                }
                case 8:
                {
                    if(y1 <= a.row/2)
                        goUp(a, x1, y1, a.row/2);
                    else
                        goDown(a, x1, y1, a.row/2);
                    if(y2 <= a.row/2)
                        goUp(a, x2, y2, a.row/2);
                    else
                        goDown(a, x2, y2, a.row/2);
                    break;
                }
                case 9:
                {
                    if(y1 <= a.row/2)
                        goDown(a, x1, y1, 0);
                    else
                        goUp(a, x1, y1, a.row);
                    if(y2 <= a.row/2)
                        goDown(a, x2, y2, 0);
                    else
                        goUp(a, x2, y2, a.row);
                    break;
                }
            }
            if(lvlcap[0] == 9)
                lvlcap[0] = 1;
            else
                lvlcap[0]++;
            break;
        }
        else
            lvlcap[0]++;
    }
}

void goUp(BoardState a, int x, int y, int m)
{
	for(int i = x + 1, u = x; i <= m; i++)
		if(a.board[i][y])
			for(; u < i; u++)
				if(!a.board[u][y])
				{
					swap(a.board[i][y], a.board[u][y]);
					u++;
					break;
				}
}

void goDown(BoardState a, int x, int y, int m)
{
	for(int i = x - 1, u = x; i > m; i--)
		if(a.board[i][y])
			for(; u > i; u--)
				if(!a.board[u][y])
				{
					swap(a.board[i][y], a.board[u][y]);
					u--;
					break;
				}
}

void goLeft(BoardState a, int x, int y, int n)
{
	for(int i = y + 1, u = y; i <= n; i++)
		if(a.board[x][i])
			for(; u < i; u++)
				if(!a.board[x][u])
				{
					swap(a.board[x][i], a.board[x][u]);
					u++;
					break;
				}
}

void goRight(BoardState a, int x, int y, int n)
{
	for(int i = y - 1, u = y; i > n; i--)
		if(a.board[x][i])
			for(; u > i; u--)
				if(!a.board[x][u])
				{
					swap(a.board[x][i], a.board[x][u]);
					u--;
					break;
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
    for (int i = 1; i < a.row + 1; i++)
        for (int j = 1; j < a.col + 1; j++)
            if(nightmare[i][j])
            {
                SetColor(a.board[i][j] % 7 + 9);
                gotoxy(i * 3 + 2, j * 5 + 2);
                cout << "-----";
                gotoxy(i * 3 + 3, j* 5 + 2);
                cout << "| " << (char) a.board[i][j] << " |";
                gotoxy(i * 3 + 4, j * 5 + 2);
                cout << "-----";
            }
    for (int i = 0; i < a.row + 2; i++)
        for (int j = 0; j < a.col + 2; j++)
            if ((rand() % 50) % 2 == 0)
                nightmare[i][j] = true;
            else
                nightmare[i][j] = false;
    SetColor(7);
    for (int i = 1; i < a.row + 1; i++)
        for (int j = 1; j < a.col + 1; j++)
            if(nightmare[i][j])
            {
                gotoxy(i * 3 + 2, j * 5 + 2);
                cout << "-----";
                gotoxy(i * 3 + 3, j* 5 + 2);
                cout << "|   |";
                gotoxy(i * 3 + 4, j * 5 + 2);
                cout << "-----";
            }
}

//////////////////////////////////////////////////////////////////////////////////////
void calculateScore(PlayerState &player)
{
    switch(player.mode)
    {
        case 1:
        {
            player.score += player.timeleft * player.lvl;
            break;
        }
        case 2:
        {
            player.score += player.timeleft * player.lvl * 2;
            break;
        }
        case 3:
        {
            player.score += player.timeleft * player.lvl * 5;
            break;
        }
        case 4:
        {
            player.score += player.timeleft * player.lvl * 9;
            break;
        }
    }
}
