#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x, y;
} st;

int W, H;
bool visited[20][20];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs()
{
    int cnt = 1;
    queue<node> q;
    q.push(st);
    while (!q.empty())
    {
        node hold = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            node tmp = hold;
            tmp.x += dir[i][0];
            tmp.y += dir[i][1];
            if (tmp.x < 0 || tmp.x >= H || tmp.y < 0 || tmp.y >= W)
                continue;
            else
            {
                if (visited[tmp.x][tmp.y] == false)
                {
                    visited[tmp.x][tmp.y] = true;
                    q.push(tmp);
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    freopen("input.in", "r", stdin);
    char str[21];
    while (cin >> W >> H)
    {
        memset(visited, false, sizeof(visited));
        if (W == 0 || H == 0)
            break;
        for (int i = 0; i < H; i++)
        {
            cin >> str;
            for (int j = 0; j < W; j++)
            {
                if (str[j] == '@')
                {
                    st.x = i;
                    st.y = j;
                    visited[i][j] = true;
                }
                else if (str[j] == '#')
                    visited[i][j] = true;
                else
                    visited[i][j] = false;
            }
        }
        int ans = bfs();
        cout << ans << '\n';
    }
}