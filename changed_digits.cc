#include <iostream>

int main ()
{
  uint64_t t {};
  std::cin >> t;
  while (t--)
  {
    uint64_t l {}, r {};
    std::cin >> l >> r;
    uint64_t power_of_ten {1};
    while (l / power_of_ten != r / power_of_ten) { power_of_ten *= 10; }
    l %= power_of_ten;
    r %= power_of_ten;
    uint64_t count {};
    while (power_of_ten != 1)
    {
      power_of_ten /= 10;
      count += (r / power_of_ten - l / power_of_ten);
    }
    std::cout << count << "\n";
  }
  return 0;
}