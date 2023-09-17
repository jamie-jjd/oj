#include <iostream>
using namespace std;

int64_t
find(
  int64_t n,
  int64_t k
) {
  if (n == 1) { return 1; }
  if (k <= ((n + 1) >> 1)) {
    int64_t i {k << 1};
    return ((i <= n) ? i : (i % n));
  }
  int64_t m {find(n >> 1, k - ((n + 1) >> 1))};
  return ((m << 1) - 1 + ((n & 1) << 1));
}

int
main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int64_t q; cin >> q;
  while (q--) {
    int64_t n, k; cin >> n >> k;
    cout << find(n, k) << "\n";
  }
  return 0;
}
