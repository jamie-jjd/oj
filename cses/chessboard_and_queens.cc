#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool
check(
  vector<string> const &cb,
  vector<int64_t> &C,
  int64_t r,
  int64_t c
) {
  if (cb[r][c] == '*') { return false; }
  for (int64_t r_ {r - 1}; r_ > -1; --r_) {
    int64_t d {r - r_};
    if (
      C[r_] == (c - d) or
      C[r_] == (c + d) or
      C[r_] == c
    ) { return false; }
  }
  return true;
}

void
place(
  vector<string> const &cb,
  vector<int64_t> &C,
  int64_t r,
  int64_t &cnt
) {
  if (r == 8) { ++cnt; return; }
  for (int64_t c {}; c < 8; ++c) {
    if (not check(cb, C, r, c)) { continue; }
    C[r] = c;
    place(cb, C, r + 1, cnt);
  }
  return;
}

int
main() {
  vector<string> cb(8);
  for (int64_t r {}; r < 8; ++r) { getline(cin, cb[r]); }
  vector<int64_t> C(8);
  int64_t cnt {};
  place(cb, C, 0, cnt);
  cout << cnt << "\n";
  return 0;
}
