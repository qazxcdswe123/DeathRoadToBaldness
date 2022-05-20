#include <bits/stdc++.h>

using namespace std;

int nn, mm;
char mapp[200][201];
int gone[200][200];
struct node
{
    int x, y, moves;
};
bool operator<(const node &me, const node &other)
{
    return me.moves > other.moves;
}
priority_queue<node> pq;
node n;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs()
{
    while (!pq.empty())
    {
        node tmp = pq.top();
        // cout << tmp.moves << "---" <<tmp.x << "---" << tmp.y << "---\n";
        pq.pop();
        int x = tmp.x;
        int y = tmp.y;
        int m = tmp.moves;

        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.x + dir[i][0];
            int ny = tmp.y + dir[i][1];
            if (nx >= 0 && nx < nn && ny >= 0 && ny < mm && mapp[nx][ny] != '#' && gone[nx][ny] != 1)
            {
                gone[nx][ny] = 1;
                if (mapp[nx][ny] == 'a')
                {
                    return m + 1;
                }
                else if (mapp[nx][ny] == '.')
                {
                    n.moves = m + 1;
                    n.x = nx;
                    n.y = ny;
                    pq.push(n);
                }
                else if (mapp[nx][ny] == 'x')
                {
                    n.moves = m + 2;
                    n.x = nx;
                    n.y = ny;
                    pq.push(n);
                }
            }
        }
    }
    return -1;
}

int main()
{
    freopen("input.in", "r", stdin);

    while (cin >> nn >> mm)
    {
        memset(mapp, 0, sizeof(mapp));
        memset(gone, 0, sizeof(gone));
        while (!pq.empty())
        {
            pq.pop();
        }
        for (int i = 0; i < nn; i++)
        {
            for (int j = 0; j < mm; j++)
            {
                cin >> mapp[i][j];
                if (mapp[i][j] == 'r')
                {
                    mapp[i][j] = '.';
                    n.x = i;
                    n.y = j;
                    n.moves = 0;
                    pq.push(n);
                    gone[i][j] = 1;
                }
            }
        }
        int ans = bfs();
        if (ans != -1)
        {
            cout << ans << '\n';
        }
        else
            cout << "Poor ANGEL has to stay in the prison all his life.\n";
        /* code */
    }
}
