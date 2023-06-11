#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int
main() {
  int n {}, x {}; cin >> n >> x;
  vector<int> p(n);
  for (auto &pi : p) { cin >> pi; }
  sort(p.begin(), p.end());
  int l {}, r {n - 1}, c {};
  while (l <= r) {
    if (p[l] + p[r] <= x) { ++l; }
    --r; ++c;
  }
  cout << c << "\n";
  return 0;
}

