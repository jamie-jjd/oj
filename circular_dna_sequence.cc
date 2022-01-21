#include <iostream>
#include <map>

int main ()
{
  std::string line;
  std::getline(std::cin, line);
  uint64_t n {std::stoull(line)};
  std::map<uint64_t, uint64_t> candidates;
  while (n--)
  {
    std::getline(std::cin, line);
    for (uint64_t i {}; i != line.size(); ++i) { candidates[i] = 0; }
    while (candidates.size() != 1 && std::get<1>(*std::begin(candidates)) != line.size())
    {
      auto const& first_pair {*std::begin(candidates)};
      auto min_element {line[(std::get<0>(first_pair) + std::get<1>(first_pair)) % line.size()]};
      for (auto const& pair : candidates)
      {
        auto element {line[(std::get<0>(pair) + std::get<1>(pair)) % line.size()]};
        if (element < min_element) { min_element = element; }
      }
      auto it {std::begin(candidates)};
      while (it != std::end(candidates))
      {
        if (line[(std::get<0>(*it) + std::get<1>(*it)) % line.size()] != min_element)
        {
          it = std::next(it);
          candidates.erase(std::prev(it));
        }
        else
        {
          ++std::get<1>(*it++);
        }
      }
    }
    {
      auto const& first_pair {*std::begin(candidates)};
      for (uint64_t i {}; i != line.size(); ++i)
      {
        std::cout << line[(std::get<0>(first_pair) + i) % line.size()];
      }
      std::cout << "\n";
    }
  }
  return 0;
}
