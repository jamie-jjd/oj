#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int
main() {
  int n {}; cin >> n;
  vector<uint64_t> p(n);
  for (auto &pi : p) { cin >> pi; }
  sort(p.begin(), p.end());
  uint64_t m {};
  if (n & 1) { m = p[n >> 1]; }
  else { m = (p[(n >> 1) - 1] + p[n >> 1]) >> 1; }
  uint64_t s {};
  for (auto const &pi : p) {
    if (pi < m) { s += m - pi; }
    else { s += pi - m; }
  }
  cout << s << "\n";
  return 0;
}

