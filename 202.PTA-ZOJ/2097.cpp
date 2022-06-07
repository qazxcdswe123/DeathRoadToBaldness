#include <iostream>
#include <cstring>

using namespace std;

int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int costs[9][9];
int visited[9][9][4];
int sx, sy, ex, ey;

void dfs(int x, int y, int state, int sum)
{
    if (visited[x][y][state] == -1 || visited[x][y][state] > sum)
    {
        visited[x][y][state] = sum;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + direction[i][0];
            int ny = y + direction[i][1];
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
            {
                int cost = costs[nx][ny] * state;
                dfs(nx, ny, (cost % 4) + 1, sum + cost);
            }
        }
    }
}

int main()
{
    freopen("input.in", "r", stdin);
    while (cin >> sx >> sy >> ex >> ey)
    {
        if (sx == 0 && sy == 0 && ex == 0 && ey == 0)
        {
            break;
        }
        sx--;
        sy--;
        ex--;
        ey--;
        memset(visited, -1, sizeof(visited));
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin >> costs[i][j];
            }
        }
        dfs(sx, sy, 1, 0);
        int minimum = 9999;
        for (int i = 0; i < 4; i++)
        {
            if (visited[ex][ey][i] != -1 && visited[ex][ey][i] < minimum)
            {
                minimum = visited[ex][ey][i];
            }
        }

        cout << minimum << '\n';
    }
}