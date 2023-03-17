#include "move.h"

bool findPath(int m, int n, int **a, int x1, int x2, int y1, int y2, vector<pair<int, int>> &route){
    if (a[x1][y1] != a[x2][y2] || a[x1][y1] == 0 || a[x2][y2] == 0) return false;

    //Tạo graph
    int **graph;
    graph = new int*[m + 2];
    for (int i = 0; i < m + 2; i++)
        graph[i] = new int [n + 2];
        
	for (int i = 0; i < m + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			graph[i][j] = (a[i][j] != 0);
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
    trace = new pair<int, int> * [m + 2];
    for (int i = 0; i < m + 2; i++)
        trace[i] = new pair<int, int> [n + 2];
    
    for (int i = 0; i < m + 2; i++)
        for (int j = 0; j < n + 2; j++)
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
			while (x >= 0 && x < m + 2 && y >= 0 && y < n + 2 && graph[x][y] == 0) {
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
    //vector<pair<int, int>> route;
	if (trace[start.first][start.second].first != -1) {
		while (start.first != -2) {
			route.push_back({ start.first, start.second});
			start = trace[start.first][start.second];
		}
	}

    for(int i = 0; i < m + 2; i++)
        delete[] graph[i];
    delete[] graph;

    for(int i = 0; i < m + 2; i++)
        delete[] trace[i];
    delete[] trace;

    return route.size() >= 2 &&  route.size() <= 4;
}

// void move(int m, int n, int **a){
//     int x1, x2, y1, y2;
//     int count = m * n;
//     while(count != 0){
//         cout << "Please input the index of the first tile: ";
//         cin >> x1 >> y1;
//         cout << "Please input the index of the second tile: ";
//         cin >> x2 >> y2;
//         if (findPath(m, n, a, x1, x2, y1, y2)){
//             a[x1][y1] = 0;
//             a[x2][y2] = 0;
//             count -= 2;
//         }
//         showBoard(m, n, a);
//     }
// }

bool checkLegalMove(int m, int n, int **a){
    vector<pair <int, int>> check[25];
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            // for (int i1 = 1; i1 <= m; i1++){
            //     for (int j1 = 1; j1 <= n; j1++){
            //         if ((i != i1 || j != j1) && findPath(m, n, a, i, i1, j, j1)){
            //             return true;
            //         }
            //     }
            // }
            if (a[i][j] != 0)
                check[a[i][j] - (int)'A'].push_back(make_pair(i, j));
        }
    }

    for (int i = 0; i < 25; i++)
        if (!check[i].empty())
            for (int j = 0; j < check[i].size() - 1; j++)
                for (int _j = j + 1; _j < check[i].size(); _j++){
                    vector<pair<int, int>> r;
                    if (findPath(m, n, a, check[i][j].first, check[i][_j].first, check[i][j].second, check[i][_j].second, r))
                        return true;  
                }
    return false;
}