#include <iostream>
#include <vector>

using namespace std;

pair<bool, vector<int>> isGroup(vector<vector<int>> &f) {
  int n = f.size();
  int e = -1; // e will store the index of the identity element, if it exists
  for (int i = 0; i < n; i++) {
    if (f[i][i] == i + 1) {
      e = i;
      break;
    }
  }
  if (e == -1) {
    return {false, {}};
  }

  // Check if the binary operation satisfies the associative property
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (f[f[i][j]][k] != f[i][f[j][k]]) {
          return {false, {}};
        }
      }
    }
  }

  // Compute the inverse of each element
  vector<int> inverse(n);
  for (int i = 0; i < n; i++) {
    inverse[i] = -1; // Inverse of i not found yet
    for (int j = 0; j < n; j++) {
      if (f[i][j] == e + 1) {
        inverse[i] = j + 1; // Inverse of i is j
        break;
      }
    }
  }
  return {true, inverse};
}

int main() {
  freopen("input.in", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> f(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> f[i][j];
        f[i][j]--; // Convert input to 0-based indices
      }
    }

    pair<bool, vector<int>> res = isGroup(f);
    if (!res.first) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) {
        cout << res.second[i] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}