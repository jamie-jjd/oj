#include <iostream>
#include <map>
#include <vector>

int main ()
{
  uint64_t n, k;
  std::cin >> n >> k;
  std::vector<uint64_t> x(n);
  if (k == 1)
  {
    for (auto& x_i : x) { std::cin >> x_i; }
    for (auto& x_i : x) { std::cout << " " << x_i; }
  }
  else
  {
    std::map<uint64_t, uint64_t> left, right;
    for (uint64_t i {}; i != k; ++i)
    {
      std::cin >> x[i];
      ++left[x[i]];
    }
    auto median {std::begin(left)};
    uint64_t count {std::get<1>(*median)};
    while (median != std::end(left) && count < (k + 1) / 2) { count += std::get<1>(*++median); }
    auto diff {count - (k + 1) / 2};
    if (diff)
    {
      right[std::get<0>(*median)] = diff;
      std::get<1>(*median) -= diff;
    }
    for (auto it {std::next(median)}; it != std::end(left); ++it)
    {
      right[std::get<0>(*it)] = std::get<1>(*it);
    }
    left.erase(std::next(median), std::end(left));
    std::cout << std::get<0>(*std::rbegin(left));
    for (uint64_t i {k}; i != n; ++i)
    {
      std::cin >> x[i];
      if (left.find(x[i - k]) != std::end(left))
      {
        if (--left[x[i - k]] == 0) { left.erase(x[i - k]); }
        auto min {std::get<0>(*std::begin(right))};
        if (--right[min] == 0) { right.erase(min); }
        ++left[min];
      }
      else
      {
        if (--right[x[i - k]] == 0) { right.erase(x[i - k]); }
      }
      if (left.empty() || x[i] <= std::get<0>(*std::rbegin(left)))
      {
        ++left[x[i]];
        auto max {std::get<0>(*std::rbegin(left))};
        if (--left[max] == 0) { left.erase(max); }
        ++right[max];
      }
      else { ++right[x[i]]; }
      std::cout << " " << std::get<0>(*std::rbegin(left));
    }
  }
  return 0;
}