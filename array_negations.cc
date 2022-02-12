#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main ()
{
  uint64_t T {};
  std::cin >> T;
  while (T--)
  {
    uint64_t n {}, k {};
    std::cin >> n >> k;
    std::vector<int64_t> a(n);
    for (auto& a_i : a) { std::cin >> a_i; }
    std::sort(std::begin(a), std::end(a));
    uint64_t i {};
    while (i != k && i != n && a[i] < 0) { a[i++] *= -1; }
    if (i < k)
    {
      auto min {*std::min_element(std::begin(a), std::end(a))};
      if ((k - i) & 1) { a[0] -= (min * 2); }
    }
    std::cout << std::accumulate(std::begin(a), std::end(a), 0) << "\n";
  }
  return 0;
}