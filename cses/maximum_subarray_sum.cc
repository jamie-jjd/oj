#include <iostream>
#include <limits>
#include <vector>

int main ()
{
  uint64_t n {};
  std::cin >> n;
  std::vector<int64_t> x(n);
  for (auto& x_i : x) { std::cin >> x_i; }
  auto max_sum {std::numeric_limits<int64_t>::min()};
  int64_t sum {};
  auto first {std::begin(x)};
  auto last {std::begin(x)};
  while (last != std::end(x))
  {
    sum += *last++;
    if (max_sum < sum) { max_sum = sum; }
    if (sum < 0)
    {
      sum = 0;
      first = last;
    }
  }
  std::cout << max_sum << "\n";
  return 0;
}