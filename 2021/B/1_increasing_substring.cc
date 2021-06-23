#include <iostream>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    cout << "Case #" << i << ": 1";
    int count = 1;
    for (string::size_type j = 1; j < S.size(); ++j) {
      if (S[j - 1] < S[j]) {
        ++count;
      } else {
        count = 1;
      }
      cout << ' ' << count;
    }
    cout << endl;
  }
  return 0;
}
