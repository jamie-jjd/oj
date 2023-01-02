#include <iostream>

int main ()
{
  uint64_t n {};
  while (std::cin >> n && n)
  {
    uint64_t a {};
    bool is_odd {true};
    uint64_t mask {1};
    while (mask)
    {
      if (n & mask)
      {
        if (is_odd) { a |= mask; }
        is_odd ^= true;
      }
      mask <<= 1;
    }
    std::cout << a << " " << (n ^ a) << "\n";
  }
}