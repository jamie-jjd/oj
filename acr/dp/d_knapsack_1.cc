#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int64_t Dfs (vector<vector<int64_t>>& V,
             vector<int64_t> const& w,
             vector<int64_t> const& v,
             int64_t r, int c) {
  if (c < 0) { return numeric_limits<int64_t>::min(); }
  if (r < 0) { return 0; }
  if (V[r][c] > 0) { return V[r][c]; }
  V[r][c] = max(Dfs(V, w, v, r - 1, c),
                Dfs(V, w, v, r - 1, c - w[r]) + v[r]);
  return V[r][c];
}

int main () {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int64_t N, W; cin >> N >> W;
  vector<vector<int64_t>> V(N, vector<int64_t>(W + 1));
  vector<int64_t> w(N), v(N);
  for (int64_t i {}; i < N; ++i) { cin >> w[i] >> v[i]; }
  for (int64_t c {W}; c >= 0; --c) { Dfs(V, w, v, N - 1, c); }
  cout << *max_element(V[N - 1].begin(), V[N - 1].end());
  return 0;
}
