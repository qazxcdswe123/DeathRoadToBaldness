#include <bits/stdc++.h>

using namespace std;

char mapp[200][201];
int gone[200][200];
struct node
{
    int x, y, moves;
} st, ed;

int dir[2] = {-1, 1};

int bfs(node n)
{
    priority_queue<node> pq;
    pq.push(n);
    while (!pq.empty())
    {
        node tmp = pq.top();
        pq.pop();
        int x = tmp.x;
        int y = tmp.y;
        int m = tmp.moves;

        for (int i = 0; i < 2; i++)
        {
            int nx = tmp.x + dir[i];
            int ny = tmp.y + dir[i];
            if (mapp[nx][ny] == 'a')
            {
                return m + 1;
            }
            else if (mapp[nx][ny] == '.' && gone[nx][ny] != 1)
            {
                gone[nx][ny] == 1;
                n.moves = m + 1;
                n.x = nx;
                n.y = ny;
                pq.push(n);
            }
            else if (mapp[nx][ny] == 'x' && gone[nx][ny] != 1)
            {
                gone[nx][ny] == 1;
                n.moves = m + 2;
                n.x = nx;
                n.y = ny;
                pq.push(n);
            }
        }
    }
}

int main()
{
    // freopen("input.in", "r", stdin);
    int n, m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mapp[i][j];
            if (mapp[i][j] == 'r')
            {
                st.x = i;
                st.y = j;
            }
            else if (mapp[i][j] == 'a')
            {
                ed.x = i;
                ed.y = j;
            }
        }
    }
}
