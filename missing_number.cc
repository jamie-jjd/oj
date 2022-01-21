#include <iostream>

int main ()
{
  uint64_t n {};
  std::cin >> n;
  uint64_t missing_number {(n * (n + 1)) >> 1};
  uint64_t integer {};
  while (--n)
  {
    std::cin >> integer;
    missing_number -= integer;
  }
  std::cout << missing_number << "\n";
  return 0;
}
