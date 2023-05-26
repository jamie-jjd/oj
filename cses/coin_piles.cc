#include <iostream>
#include <vector>

using namespace std;

int
main() {
  int64_t t {}, a {}, b {};
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a < b) { swap(a, b); }
    int64_t d {a - b};
    a -= (d << 1);
    b -= d;
    if (a < 0 or b < 0 or a % 3 or b % 3) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
  return 0;
}
