#include <iostream>

using namespace std;

int
main() {
  uint64_t n {};
  cin >> n;
  if (n >= 1) { cout << "0\n"; }
  if (n >= 2) { cout << "6\n"; }
  for (uint64_t k {3}; k <= n; ++k) {
    /* C(k^2, 2) - ((k - 1) * (k - 2) * 4) */
    cout << (k * ((k * (k + 1)) / 2) - (4 * (k - 2))) * (k - 1) << "\n";
  }
  return 0;
}
