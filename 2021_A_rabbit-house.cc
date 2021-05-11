#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  vector<int> dir{0, 1, 0, -1, 0};
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    // Input
    int R, C;
    cin >> R >> C;
    vector<vector<int>> G(R, vector<int>(C));
    auto cmp = [](const vector<int> &a, const vector<int> &b) {
      return a[0] < b[0];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        cin >> G[i][j];
        pq.push({G[i][j], i, j});
      }
    }

    // Calculate
    long long res = 0;
    while (!pq.empty()) {
      vector<int> curr = pq.top();
      pq.pop();
      if (curr[0] != G[curr[1]][curr[2]]) continue;
      for (int i = 0; i < 4; ++i) {
        vector<int> next{0, curr[1] + dir[i], curr[2] + dir[i + 1]};
        if (0 <= next[1] && next[1] < R && 0 <= next[2] && next[2] < C &&
            G[next[1]][next[2]] < G[curr[1]][curr[2]] - 1) {
          res += G[curr[1]][curr[2]] - 1 - G[next[1]][next[2]];
          next[0] = G[next[1]][next[2]] = G[curr[1]][curr[2]] - 1;
          pq.push(next);
        }
      }
    }

    // Output
    cout << "Case #" << t << ": " << res << endl;
  }
  return 0;
}
