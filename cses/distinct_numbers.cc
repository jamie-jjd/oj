#include <iostream>
#include <set>

using namespace std;

int
main() {
  int n {}; cin >> n;
  set<int> s;
  for (int i {}, x {}; i < n; ++i) {
    cin >> x;
    s.emplace(x);
  }
  cout << s.size() << "\n";
  return 0;
}

