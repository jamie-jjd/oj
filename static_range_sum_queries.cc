#include <iostream>
#include <numeric>
#include <vector>

int main ()
{
  uint64_t n {}, q {};
  std::cin >> n >> q;
  std::vector<uint64_t> x(n + 1);
  for (uint64_t i {1}; i <= n; ++i) { std::cin >> x[i]; }
  std::partial_sum(x.begin(), x.end(), x.begin());
  while (q--)
  {
    uint64_t a {}, b {};
    std::cin >> a >> b;
    std::cout << (x[b] - x[a - 1]) << "\n";
  }
  return 0;
}