#include <iomanip>
#include <iostream>

int main ()
{
  uint64_t n {};
  std::cin >> n;
  while (n--)
  {
    uint64_t s {};
    uint64_t d {};
    std::cin >> s >> d;
    if (d <= s && (s & 1) == (d & 1))
    {
      std::cout << ((s + d) >> 1) << " " << ((s - d) >> 1) << "\n";
    }
    else
    {
      std::cout << "impossible\n";
    }
  }
  return 0;
}
