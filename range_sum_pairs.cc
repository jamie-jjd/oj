#include <algorithm>
#include <iostream>
#include <vector>

int main ()
{
  uint64_t t {};
  std::cin >> t;
  while (t--)
  {
    uint64_t n {}, l {}, r {};
    std::cin >> n >> l >> r;
    std::vector<uint64_t> a(n);
    for (auto& a_i : a) { std::cin >> a_i; }
    std::sort(std::begin(a), std::end(a));
    uint64_t count {};
    for (auto it {std::begin(a)}; it != std::end(a) && *it < r; ++it)
    {
      auto diff {(*it < l) ? (l - *it) : (*it - l)};
      auto first {std::lower_bound(std::next(it), std::end(a), diff)};
      auto last {std::upper_bound(std::next(it), std::end(a), r - *it)};
      count += std::distance(first, last);
    }
    std::cout << count << "\n";
  }
}