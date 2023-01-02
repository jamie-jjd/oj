#include <iostream>

int main ()
{
  uint64_t c {};
  while (std::cin >> c && c)
  {
    while (c--)
    {
      uint64_t x {}, y {}, n {};
      std::cin >> x >> y >> n;
      uint64_t result {1};
      uint64_t two_power_of_x {x % n};
      while (y)
      {
        if (y & 1) { result = (result * two_power_of_x) % n; }
        two_power_of_x = (two_power_of_x * two_power_of_x) % n;
        y >>= 1;
      }
      std::cout << result << "\n";
    }
  }
  return 0;
}