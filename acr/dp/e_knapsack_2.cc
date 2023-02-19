#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void update (int64_t& c, int64_t c_) {
  if (c == 0 or c_ < c) { c = c_; }
  return;
}

int main () {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int64_t N, W; cin >> N >> W;
  vector<int64_t> w(N), v(N);
  for (int64_t i {}; i < N; ++i) { cin >> w[i] >> v[i]; }
  int64_t V {accumulate(v.begin(), v.end(), 0)};
  vector<vector<int64_t>> C(2, vector<int64_t>(V + 1));
  C[0][v[0]] = w[0];
  for (int64_t i {}; i < (N - 1); ++i) {
    auto p {i & 1}, q {1 - p};
    fill(C[q].begin(), C[q].end(), 0);
    update(C[q][v[i + 1]], w[i + 1]);
    for (int64_t j {}; j <= V; ++j) {
      if (C[p][j]) {
        update(C[q][j], C[p][j]);
        update(C[q][j + v[i + 1]], C[p][j] + w[i + 1]);
      }
    }
  }
  for (int64_t i {V}; i >= 0; --i) {
    auto const& c {C[(N - 1)& 1][i]};
    if (0 < c and c <= W) { cout << i; break; }
  }
  return 0;
}
