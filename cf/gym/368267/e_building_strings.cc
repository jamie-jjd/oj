#include <iostream>
#include <map>
#include <vector>

int main ()
{
  uint64_t T {};
  std::cin >> T;
  while (T--)
  {
    uint64_t n {}, m {};
    std::cin >> n >> m;
    std::string c, cost;
    std::cin >> c >> cost;
    std::map<char, uint64_t> c_cost;
    for (uint64_t i {}; i != n; ++i)
    {
      cost[i] -= '0';
      auto it {c_cost.find(c[i])};
      if (it != std::end(c_cost)) { if (cost[i] < std::get<1>(*it)) { std::get<1>(*it) = cost[i]; } }
      else                        { c_cost[c[i]] = cost[i]; }
    }
    std::cin >> c;
    bool is_buildable {true};
    int64_t sum {};
    for (uint64_t i {}; i != m && is_buildable; ++i)
    {
      auto it {c_cost.find(c[i])};
      if (it != std::end(c_cost)) { sum += std::get<1>(*it); }
      else                        { is_buildable = false; }
    }
    std::cout << ((is_buildable) ? sum : -1) << "\n";
  }
  return 0;
}