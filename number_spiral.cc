#include <iostream>

int main ()
{
  uint64_t t {};
  std::cin >> t;
  while (t--)
  {
    uint64_t y {}, x {};
    std::cin >> y >> x;
    auto max {(y < x) ? x : y};
    std::cout << (1 + max * (max - 1) + ((max & 1) ? (x - y) : (y - x))) << "\n";
  }
  return 0;
}