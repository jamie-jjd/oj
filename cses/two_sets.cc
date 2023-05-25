#include <iostream>
#include <vector>

using namespace std;

int
main() {
  uint64_t n {};
  cin >> n;
  uint64_t sum {n * (n + 1)};
  if (sum & 0x3) {
    cout << "NO\n";
  }
  else {
    cout << "YES\n";
    sum >>= 2;
    vector<uint64_t> v;
    for (uint64_t i {n}; i && sum; --i) {
      if (sum < i) { continue; }
      sum -= i;
      v.emplace_back(i);
    }
    cout << v.size() << "\n";
    for (auto itr {v.rbegin()}; itr != v.rend(); ++itr) {
      cout << *itr << " ";
    }
    cout << "\n" << (n - v.size()) << "\n"; 
    for (uint64_t i {1}; i <= n; ++i) {
      if (i < v.back()) { cout << i << " "; }
      else { v.pop_back(); }
    }
    cout << "\n";
  }
  return 0;
}
