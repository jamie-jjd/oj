#include <iostream>

using namespace std;

int
main() {
  int64_t q {}; cin >> q;
  while (q--) {
    int64_t k {}; cin >> k;
    int64_t x {9}, l {1};
    while ((x * l) < k) { k -= (x * l); x *= 10; ++l; }
    x = (x / 9) + ((k - 1) / l);
    k = l - ((k - 1) % l);
    while (--k) { x /= 10; }
    cout << (x % 10) << "\n";
  }
  return 0;
}
