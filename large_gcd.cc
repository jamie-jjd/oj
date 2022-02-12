#include <iostream>

int main ()
{
  uint64_t T {};
  std::cin >> T;
  while (T--)
  {
    uint64_t n {}, m {};
    std::cin >> n >> m;
    std::cout << ((n & 1 && m & 1) ? 12 : 2) << "\n";
  }
  return 0;
}