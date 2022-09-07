#include <iostream>
#include <vector>

using namespace std;
int aa = 10;

void solve(int n, int src, int des, int helper)
{
    if (n == 1)
    {
        cout << "Moving disc 1 from " << src << " to " << des << endl;
        return;
    }
    solve(n - 1, src, helper, des);
    cout << "Moving disc " << n << "from " << 1 << " to " << des << endl;
    solve(n - 1, helper, des, src);
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(i + 10);
    }

    // solve(n, 1, 3, 2);
    return 0;
}