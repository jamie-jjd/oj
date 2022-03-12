#include <iostream>

int main ()
{
  uint64_t n;
  std::cin >> n;
  if (n > 3)
  {
    for (uint64_t i {n - (n & 1)}; i >= 6; i -= 2) { std::cout << i << "\n"; }
    std::cout << "2\n4\n1\n3\n";
    for (uint64_t i {5}; i <= n - !(n & 1); i += 2) { std::cout << i << "\n"; }
  }
  else if (n == 2 || n == 3) { std::cout << "NO SOLUTION\n"; }
  else                       { std::cout << "1\n"; }
  return 0;
}