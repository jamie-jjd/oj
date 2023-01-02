#include <iostream>
#include <vector>

int main ()
{
  uint64_t n {};
  uint64_t m {};
  std::cin >> n >> m;
  std::vector<bool> is_occurred(n);
  std::vector<uint64_t> e(m);
  for (auto& e_i : e) { std::cin >> e_i; }
  for (auto it {std::rbegin(e)}; it != std::rend(e); ++it)
  {
    if (!is_occurred[*it - 1])
    {
      is_occurred[*it - 1] = true;
      std::cout << *it << "\n";
    }
  }
  for (uint64_t i {}; i != n; ++i)
  {
    if (!is_occurred[i]) { std::cout << (i + 1) << "\n"; }
  }
  return 0;
}