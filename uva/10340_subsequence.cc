#include <iostream>

int main ()
{
  std::string s, t;
  while (std::cin >> s >> t)
  {
    bool is_subsequence {};
    auto it_s {std::begin(s)};
    if (s.size() <= t.size())
    {
      for (auto it_t {std::begin(t)}; it_t != std::end(t) && it_s != std::end(s); ++it_t)
      {
        if (*it_t == *it_s) { ++it_s; }
      }
    }
    std::cout << ((it_s == std::end(s)) ? "Yes" : "No") << "\n";
  }
  return 0;
}
