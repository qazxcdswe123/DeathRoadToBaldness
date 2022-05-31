#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x, y, z;
    int time;
} st, ed;

int L, R, C;
char mapp[30][30][31];
int gone[30][30][30];
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};
int dz[6] = {1, -1, 0, 0, 0, 0};

bool canPlace(int x, int y, int z);
int bfs(node s);

int main()
{
    freopen("input.in", "r", stdin);
    while (cin >> L >> R >> C)
    {
        if (L == 0 && R == 0 && C == 0)
        {
            return 0;
        }

        memset(gone, 0, sizeof(gone));

        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                for (int k = 0; k < C; k++)
                {
                    cin >> mapp[i][j][k];
                    if (mapp[i][j][k] == 'S')
                    {
                        st.x = i;
                        st.y = j;
                        st.z = k;
                        st.time = 0;
                    }
                    else if (mapp[i][j][k] == 'E')
                    {
                        ed.x = i;
                        ed.y = j;
                        ed.z = k;
                    }
                }
            }
        }
        int ans = bfs(st);
        if (ans == -1)
        {
            cout << "Trapped!" << '\n';
        }
        else
        {
            cout << "Escaped in " << ans << " minute(s)." << '\n';
        }
    }
    // cin.ignore();
}

bool canPlace(int x, int y, int z)
{
    if (x >= 0 && x < L && y >= 0 && y < R && z >= 0 && z < C)
        return true;
    return false;
}

int bfs(node st)
{
    queue<node> q;
    int x, y, z, t;
    q.push(st);
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        x = temp.x;
        y = temp.y;
        z = temp.z;
        t = temp.time;
        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (canPlace(nx, ny, nz) && gone[nx][ny][nz] != 1 && mapp[nx][ny][nz] != '#')
            {
                if (nx == ed.x && ny == ed.y && nz == ed.z)
                {
                    return t + 1;
                }
                gone[nx][ny][nz] = 1;
                st.x = nx;
                st.y = ny;
                st.z = nz;
                st.time = t + 1;
                q.push(st);
            }
        }
    }
    return -1;
}