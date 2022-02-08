#include <iostream>
#include <list>

int main ()
{
  uint64_t X {};
  std::list<uint64_t> list;
  auto median {std::end(list)};
  while (std::cin >> X)
  {
    auto it {std::begin(list)};
    while (it != std::end(list) && *it < X) { ++it; }
    list.insert(it, X);
    if (list.size() & 1)
    {
      if (*median <= X) { median = std::next(median); }
      std::cout << *median << "\n";
    }
    else
    {
      if (X <= *median) { median = std::prev(median); }
      std::cout << (*median + *std::next(median)) / 2 << "\n";
    }
  }
  return 0;
}