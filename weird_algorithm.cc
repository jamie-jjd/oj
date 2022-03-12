#include <iostream>

int main ()
{
  uint64_t n;
  std::cin >> n;
  std::cout << n;
  while (n != 1)
  {
    if (n & 1) { n = 3 * n + 1; }
    else       { n /= 2; }
    std::cout << " " << n;
  }
  return 0;
}