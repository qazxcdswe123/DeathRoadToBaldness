#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

string a, b;
int dp[1001][1001];

// int LCS(int i, int j) {
//   if (i == 0 || j == 0) {
//     return 0;
//   }

//   if (a[i - 1] == b[j - 1]) {
//     return LCS(i - 1, j - 1) + 1;
//   } else {
//     return max(LCS(i - 1, j), LCS(i, j - 1));
//   }
// }

int main() {
  // freopen("input.in", "r", stdin);
  while (cin >> a >> b) {
    int l1 = a.length();
    int l2 = b.length();

    for (int i = 0; i <= l1; i++)
      dp[i][0] = 0;
    for (int i = 0; i <= l2; i++)
      dp[0][i] = 0;

    for (int i = 1; i <= l1; i++) {
      for (int j = 1; j <= l2; j++) {
        if (a[i - 1] == b[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    cout << dp[l1][l2] << '\n';
  }
}
