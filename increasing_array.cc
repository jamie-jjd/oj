#include <iostream>
#include <vector>

int main ()
{
  uint64_t n {};
  std::cin >> n;
  uint64_t amount_moves {};
  uint64_t prev_x {};
  uint64_t x {};
  std::cin >> prev_x;
  while (--n)
  {
    std::cin >> x;
    if (prev_x > x)
    {
      amount_moves += (prev_x - x);
      x = prev_x;
    }
    prev_x = x;
  }
  std::cout << amount_moves << "\n";
  return 0;
}
