#include <iostream>
#include <vector>

int main ()
{
  uint64_t n {};
  std::cin >> n;
  std::vector<bool> is_existed(n + 1);
  uint64_t x {};
  uint64_t count {};
  for (uint64_t i {}; i != n; ++i)
  {
    std::cin >> x;
    if (!is_existed[x - 1]) { ++count; }
    is_existed[x] = true;
  }
  std::cout << count << "\n";
  return 0;
}