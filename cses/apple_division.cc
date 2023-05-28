#include <iostream>
#include <vector>

using namespace std;

int
main() {
  int64_t n {};
  cin >> n;
  vector<int64_t> p(n);
  int64_t s {};
  for (auto &x : p) { cin >> x; s += x; }
  int64_t d {s};
  int64_t cnt {1LL << n};
  while (--cnt) {
    int64_t s0 {}, s1 {};
    for (int64_t i {}, m {1}; i < n; ++i, m <<= 1) {
      if (cnt & m) { s1 += p[i]; }
      else { s0 += p[i]; }
    }
    if (s0 < s1) { swap(s0, s1); }
    if ((s0 - s1) < d) { d = s0 - s1; }
  }
  cout << d << "\n";
  return 0;
}
