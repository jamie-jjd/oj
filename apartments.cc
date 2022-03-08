#include <algorithm>
#include <iostream>
#include <vector>

int main ()
{
  int64_t n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int64_t> a(n);
  for (auto& a_i : a) { std::cin >> a_i; }
  std::sort(a.begin(), a.end());
  std::vector<int64_t> b(m);
  for (auto& b_i : b) { std::cin >> b_i; }
  std::sort(b.begin(), b.end());
  auto it_a {a.begin()}, it_b {b.begin()};
  uint64_t count {};
  while (it_a != a.end() && it_b != b.end())
  {
    if (*it_b < *it_a - k)      { ++it_b; }
    else if (*it_b > *it_a + k) { ++it_a; }
    else                        { ++it_b; ++it_a; ++count; }
  }
  std::cout << count;
  return 0;
}