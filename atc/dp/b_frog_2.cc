#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int64_t N, K; cin >> N >> K;
  vector<int64_t> H(N);
  for (auto& h : H) { cin >> h; }
  vector<int64_t> C(N, numeric_limits<int64_t>::max());
  C[0] = 0;
  for (int64_t i {}; i < N; ++i) {
    for (int64_t j {i + 1}; j <= i + K and j < N; ++j) {
      auto c {C[i] + llabs(H[j] - H[i])};
      if (c < C[j]) { C[j] = c; };
    }
  }
  cout << C[N - 1];
  return 0;
}
