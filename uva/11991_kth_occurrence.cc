#include <iostream>
#include <vector>

int main ()
{
  uint64_t n {};
  uint64_t m {};
  while (std::cin >> n >> m)
  {
    std::vector<std::vector<uint64_t>> positions(1000000);
    uint64_t v {};
    for (uint64_t i {}; i != n; ++i)
    {
      std::cin >> v;
      positions[v - 1].push_back(i);
    }
    uint64_t k {};
    while (m--)
    {
      std::cin >> k >> v;
      std::cout << ((k <= positions[v - 1].size()) ? ((positions[v - 1][k - 1]) + 1): 0) << "\n";
    }
  }
  return 0;
}