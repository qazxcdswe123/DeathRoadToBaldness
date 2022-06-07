#include <iostream>

using namespace std;

int maxn = 110;

int main()
{
    // freopen("input.in", "r", stdin);
    int i, x, N, n, a[maxn], isStack, isQueue;
    cin >> n;
    while (n--)
    {
        cin >> N;
        for (i = 0; i < N; i++)
            cin >> a[i];
        isStack = isQueue = 1;
        for (i = 0; i < N; i++)
        {
            cin >> x;
            if (x != a[i])
                isQueue = 0;
            if (x != a[N - 1 - i])
                isStack = 0;
        }
        if (isQueue && isStack)
            cout << "both" << endl;
        else if (isQueue)
            cout << "queue" << endl;
        else if (isStack)
            cout << "stack" << endl;
        else
            cout << "neither" << endl;
    }
    return 0;
}