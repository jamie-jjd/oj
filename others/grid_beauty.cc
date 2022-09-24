#include <iostream>
#include <map>
#include <vector>

int main ()
{
  std::ios_base::sync_with_stdio(false);
  uint64_t T {};
  std::cin >> T;
  while (T--)
  {
    uint64_t n {}, m {};
    std::cin >> n >> m;
    uint64_t count {};
    std::vector<uint64_t> row_0(m);
    std::vector<uint64_t> row_1(m);
    std::map<uint64_t, uint64_t> digit_count;
    for (uint64_t i {}; i != n; ++i)
    {
      auto& row_p {(i & 1) ? row_0 : row_1};
      auto& row_c {(i & 1) ? row_1 : row_0};
      for (auto& e : row_c) { std::cin >> e; }
      for (auto& e : row_p)
      {
        auto it {digit_count.find(e)};
        if (it != std::end(digit_count)) { ++std::get<1>(*it); }
        else                             { digit_count[e] = 1; }
      }
      if (i)
      {
        for (auto e : row_c)
        {
          auto it {digit_count.find(e)};
          if (it != std::end(digit_count) && std::get<1>(*it))
          {
            ++count;
            --std::get<1>(*it);
          }
        }
      }
      digit_count.clear();
    }
    std::cout << count << "\n";
  }
  return 0;
}