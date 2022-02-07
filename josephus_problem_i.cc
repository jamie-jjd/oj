#include <iostream>
#include <list>

int main ()
{
  uint64_t n {};
  std::cin >> n;
  std::list<uint64_t> list;
  for (uint64_t i {}; i != n; ++i) { list.push_back(i + 1); }
  auto it {std::begin(list)};
  while (list.size() > 1)
  {
    if (std::next(it) == std::end(list))
    {
      std::cout << *std::begin(list) << " ";
      it = list.erase(std::begin(list));
    }
    else if (std::next(it) == std::prev(std::end(list)))
    {
      std::cout << *std::prev(std::end(list)) << " ";
      list.erase(std::prev(std::end(list)));
      it = std::begin(list);
    }
    else
    {
      std::cout << *std::next(it) << " ";
      it = list.erase(std::next(it));
    }
  }
  std::cout << *it << "\n";
  return 0;
}