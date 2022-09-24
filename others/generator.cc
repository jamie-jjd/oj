#include <array>
#include <iostream>

int main ()
{
  std::array<uint64_t, 100100> generator {};
  for (uint64_t i {1}; i <= 100000; ++i)
  {
    auto sum {i};
    for (auto j {i}; j; j /= 10) { sum += j % 10; }
    if (generator[sum] == 0) { generator[sum] = i; }
  }
  uint64_t n {};
  std::cin >> n;
  while (n--)
  {
    uint64_t integer {};
    std::cin >> integer;
    std::cout << generator[integer] << "\n";
  }
  return 0;
}
