#include <iostream>
#include <string>

using namespace std;

int
main() {
  string s;
  cin >> s;
  int64_t cnt[26] {};
  for (auto c : s) { ++cnt[c - 'A']; }
  size_t oddCnt {};
  for (auto c : cnt) { oddCnt += (c & 0x1); }
  if (oddCnt != (s.size() & 0x1)) {
    cout << "NO SOLUTION\n";
    return 0;
  }
  string p;
  char c {};
  for (int64_t i {}; i < 26; ++i) {
    if (cnt[i] & 0x1) { c = 'A' + i; --cnt[i]; }
    int64_t j {cnt[i] >> 1};
    cnt[i] -= j;
    while (j--) { p.push_back('A' + i); }
  }
  if (c) { p.push_back(c); }
  for (int64_t i {25}; i >= 0; --i) {
    while (cnt[i]--) { p.push_back('A' + i); }
  }
  cout << p << "\n";
  return 0;
}
