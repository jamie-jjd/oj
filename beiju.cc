#include <iostream>
#include <list>

int main ()
{
  std::string line;
  while (std::getline(std::cin, line))
  {
    std::list<char> beiju;
    auto it {std::end(beiju)};
    for (auto const& c : line)
    {
      if (c == '[')       { it = std::begin(beiju); }
      else if (c == ']')  { it = std::end(beiju); }
      else                { it = std::next(beiju.insert(it, c)); }
    }
    for (auto const& c : beiju) { std::cout << c; }
    std::cout << "\n";
  }
}