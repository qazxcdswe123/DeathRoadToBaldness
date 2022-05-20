#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#define MAX 201
using namespace std;
typedef struct ANG
{
    int t;
    int x, y;
} ANG;
char map[MAX][MAX];
int vis[MAX][MAX];
int n, m;
int dir[8] = {0, 1, 0, -1, 1, 0, -1, 0};
priority_queue<ANG> q;
bool operator<(ANG a, ANG b)
{
    return a.t > b.t;
}
int BFS()
{
    ANG tmp;
    int i, x, a, b, aa, bb, t;
    while (!q.empty())
    {
        tmp = q.top();
        q.pop();
        a = tmp.x;
        b = tmp.y;
        t = tmp.t;
        for (i = 0; i < 8; i += 2)
        {
            aa = a + dir[i];
            bb = b + dir[i + 1];
            if (aa >= 0 && aa < n && bb >= 0 && b < m && map[aa][bb] != '#' && !vis[aa][bb])
            {
                vis[aa][bb] = 1;
                if (map[aa][bb] == 'a')
                    return t + 1;

                if (map[aa][bb] == '.')
                {
                    tmp.t = t + 1;
                    tmp.x = aa;
                    tmp.y = bb;
                    q.push(tmp);
                }
                if (map[aa][bb] == 'x')
                {
                    tmp.t = t + 2;
                    tmp.x = aa;
                    tmp.y = bb;
                    q.push(tmp);
                }
            }
        }
    }
    return -1;
}
int main()
{
    freopen("input.in", "r", stdin);
    int i, k, ans;
    ANG tmp;
    while (~scanf("%d%d", &n, &m))
    {
        memset(map, 0, sizeof(map));
        for (i = 0; i < n; i++)
            scanf("%s", map[i]);

        while (!q.empty())
            q.pop();
        memset(vis, 0, sizeof(vis));

        for (i = 0; i < n; i++)
            for (k = 0; k < m; k++)
                if (map[i][k] == 'r')
                {
                    map[i][k] = '.';
                    tmp.x = i;
                    tmp.y = k;
                    tmp.t = 0;
                    q.push(tmp);
                    vis[i][k] = 1;
                }
        ans = BFS();
        if (ans != -1)
            printf("%d\n", ans);
        else
            printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
    return 0;
}
