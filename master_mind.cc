#include <iostream>
#include <vector>

int main ()
{
  uint64_t index {};
  uint64_t n {};
  while ((std::cin >> n) && n)
  {
    std::cout << "Game " << (++index) << ":\n";
    std::vector<uint64_t> s(n);
    std::vector<uint64_t> count_s(10);
    for (auto& s_i : s)
    {
      std::cin >> s_i;
      ++count_s[s_i];
    }
    std::vector<uint64_t> g(n);
    while (true)
    {
      for (auto& g_i : g) { std::cin >> g_i; }
      if (g[0])
      {
        std::vector<uint64_t> count(count_s);
        uint64_t count_strong {};
        uint64_t count_weak {};
        for (uint64_t i {}; i != n; ++i)
        {
          if (s[i] == g[i])
          {
            ++count_strong;
            --count[g[i]];
          }
        }
        for (uint64_t i {}; i != n; ++i)
        {
          if (s[i] != g[i] && count[g[i]])
          {
            ++count_weak;
            --count[g[i]];
          }
        }
        std::cout << "    (" << count_strong << "," << count_weak << ")\n";
      }
      else { break; }
    }
  }
}