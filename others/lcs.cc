#include <deque>
#include <iostream>
#include <vector>

int main ()
{
  std::string s, t;
  std::cin >> s >> t;
  std::vector<std::vector<uint64_t>> lcs(s.size() + 1, std::vector<uint64_t>(t.size() + 1));
  for (uint64_t r {}; r != s.size(); ++r)
  {
    for (uint64_t c {}; c != t.size(); ++c)
    {
      auto i {r + 1}, j {c + 1};
      if (s[r] == t[c]) { lcs[i][j] = lcs[i - 1][j - 1] + 1; }
      else              { lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]); }
    }
  }
  std::deque<char> lcs_st;
  uint64_t i {s.size()}, j {t.size()};
  while (i && j)
  {
    auto r {i - 1}, c {j - 1};
    if (s[r] == t[c])
    {
      lcs_st.push_front(s[r]);
      i -= (i != 0); j -= (j != 0);
    }
    else if (lcs[i][j - 1] < lcs[i - 1][j]) { i -= (i != 0); }
    else                                    { j -= (j != 0); }
  }
  for (auto c : lcs_st) { std::cout << c; }
  return 0;
}