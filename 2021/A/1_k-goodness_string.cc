#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int score = 0;
    for (int i = 0; i <= N / 2 - 1; ++i) {
      if (S[i] != S[N - 1 - i]) ++score;
    }
    cout << "Case #" << t << ": " << abs(K - score) << endl;
  }
  return 0;
}
