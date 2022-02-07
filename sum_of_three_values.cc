#include <algorithm>
#include <iostream>
#include <vector>

int main ()
{
  uint64_t n {};
  uint64_t x {};
  std::cin >> n >> x;
  std::vector<std::pair<uint64_t, uint64_t>> sorted_a(n);
  for (uint64_t i {}, a_i {}; i != n; ++i)
  {
    std::cin >> a_i;
    sorted_a[i] = {a_i, i};
  }
  bool is_found {};
  if (n > 2)
  {
    std::sort
    (
      std::begin(sorted_a),
      std::end(sorted_a),
      [] (auto const& lhs, auto const& rhs)
      {
        return (std::get<0>(lhs) < std::get<0>(rhs));
      }
    );
    for
    (
      auto it_0 {std::begin(sorted_a)};
      it_0 != std::prev(std::end(sorted_a), 2) && std::get<0>(*it_0) < x && !is_found;
      ++it_0
    )
    {
      auto it_1 {std::next(it_0)};
      auto it_2 {std::prev(std::end(sorted_a))};
      while (it_1 != it_2 && !is_found)
      {
        auto sum {std::get<0>(*it_0) + std::get<0>(*it_1) + std::get<0>(*it_2)};
        if (sum < x)
        {
          ++it_1;
        }
        else if (sum > x)
        {
          --it_2;
        }
        else
        {
          is_found = true;
          std::cout
          << (std::get<1>(*it_0) + 1) << " "
          << (std::get<1>(*it_1) + 1) << " "
          << (std::get<1>(*it_2) + 1) << "\n";
        }
      }
    }
  }
  if (!is_found) { std::cout << "IMPOSSIBLE\n"; }
  return 0;
}