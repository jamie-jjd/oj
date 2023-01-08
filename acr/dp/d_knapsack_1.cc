#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int64_t N, W; cin >> N >> W;
  vector<vector<int64_t>> C(N, vector<int64_t>(W + 1));
  vector<int64_t> w(N), v(N);
  for (int64_t i {}; i < N; ++i) { cin >> w[i] >> v[i]; }
  C[0][w[0]] = v[0];
  for (int64_t i {1}; i < N; ++i) {
    for (int64_t j {1}; j <= W; ++j) {
      if (C[i - 1][j] > C[i][j]) { C[i][j] = C[i - 1][j]; }
      if (j >= w[i]) {
        auto c {C[i - 1][j - w[i]] + v[i]};
        if (c > C[i][j]) { C[i][j] = c; };
      }
    }
  }
  cout << *max_element(C[N - 1].begin(), C[N - 1].end());
  return 0;
}
