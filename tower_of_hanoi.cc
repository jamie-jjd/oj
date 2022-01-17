#include <iostream>

void Hanoi (uint64_t n, uint64_t from, uint64_t to)
{
  if (n)
  {
    auto buffer {6 - from - to};
    Hanoi(n - 1, from, buffer);
    std::cout << from << " " << to << "\n";
    Hanoi(n - 1, buffer, to);    
  }
  return;
}

int main ()
{
  uint64_t n {};
  std::cin >> n;
  std::cout << ((1ULL << n) - 1) << "\n";
  Hanoi(n, 1, 3);
  return 0;
}
