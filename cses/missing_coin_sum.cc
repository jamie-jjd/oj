#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int
main() {
  int n {}; cin >> n;
  vector<uint64_t> x(n);
  for (auto &xi : x) { cin >> xi; }
  sort(x.begin(), x.end());
  uint64_t s {};
  for (auto const& xi : x) {
    if (s + 1 < xi) { break; }
    s += xi;
  }
  cout << (s + 1) << "\n";
  return 0;
}

