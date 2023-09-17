#include <iostream>
using namespace std;

int
main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int64_t n; cin >> n;
  while (n--) {
    int64_t a, b; cin >> a >> b;
    int64_t p {1};
    while (b) {
      if (b & 1) { p = (p * a) % 1'000'000'007; }
      a = (a * a) % 1'000'000'007;
      b >>= 1;
    }
    cout << p << "\n";
  }
  return 0;
}
