#include <iostream>
#include <numeric>
#include <vector>

int main ()
{
  std::string s, t;
  std::getline(std::cin, s);
  std::getline(std::cin, t);
  std::vector<std::vector<uint64_t>> cost(2, std::vector<uint64_t>(t.size() + 1));
  uint64_t cur {};
  std::iota(cost[cur].begin(), cost[cur].end(), 0);
  for (uint64_t r {1}; r <= s.size(); ++r)
  {
    cur = 1 - cur;
    cost[cur][0] = r;
    for (uint64_t c {1}; c <= t.size(); ++c)
    {
      cost[cur][c] = (s[r - 1] == t[c - 1]) ? (cost[1 - cur][c - 1])
                                            : (std::min(std::min(cost[1 - cur][c - 1], cost[1 - cur][c]), cost[cur][c - 1]) + 1);
    }
  }
  std::cout << cost[cur][t.size()] << "\n";
  return 0;
}