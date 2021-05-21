#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    // Input
    int R, C;
    cin >> R >> C;
    vector<vector<int>> grid(R, vector<int>(C));
    for (auto &row : grid) {
      for (auto &cell : row) {
        cin >> cell;
      }
    }

    // Calculate consecutive good cells in each direction
    vector<vector<int>> left(R, vector<int>(C));
    vector<vector<int>> right(R, vector<int>(C));
    vector<vector<int>> up(R, vector<int>(C));
    vector<vector<int>> down(R, vector<int>(C));
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (grid[i][j] == 0) continue;
        if (i-1 >= 0) up[i][j] = up[i-1][j] + 1;
        else up[i][j] = 1;
        if (j-1 >= 0) left[i][j] = left[i][j-1] + 1;
        else left[i][j] = 1;
      }
    }
    for (int i = R-1; i >= 0; --i) {
      for (int j = C-1; j >= 0; --j) {
        if (grid[i][j] == 0) continue;
        if (i+1 < R) down[i][j] = down[i+1][j] + 1;
        else down[i][j] = 1;
        if (j+1 < C) right[i][j] = right[i][j+1] + 1;
        else right[i][j] = 1;
      }
    }

    // Calculate the number of L-shapes
    int count = 0;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        count += max(0, min(left[i][j] / 2, up[i][j]) - 1);
        count += max(0, min(left[i][j] / 2, down[i][j]) - 1);
        count += max(0, min(right[i][j] / 2, up[i][j]) - 1);
        count += max(0, min(right[i][j] / 2, down[i][j]) - 1);
        count += max(0, min(up[i][j] / 2, left[i][j]) - 1);
        count += max(0, min(up[i][j] / 2, right[i][j]) - 1);
        count += max(0, min(down[i][j] / 2, left[i][j]) - 1);
        count += max(0, min(down[i][j] / 2, right[i][j]) - 1);
      }
    }

    // Output
    cout << "Case #" << t << ": " << count << endl;
  }
  return 0;
}
