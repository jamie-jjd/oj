#include <iostream>

int main ()
{
  uint64_t n {};
  std::cin >> n;
  uint64_t exponent_2 {};
  uint64_t exponent_5 {};
  for (uint64_t i {1}; (1ULL << i) <= n; ++i)
  {
    exponent_2 += (n >> i);
  }
  for (uint64_t i {5}; i <= n; i *= 5)
  {
    exponent_5 += (n / i);
  }
  std::cout << ((exponent_2 < exponent_5) ? exponent_2 : exponent_5) << "\n";
  return 0;
}
