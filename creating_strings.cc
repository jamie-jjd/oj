#include <algorithm>
#include <iostream>
#include <set>

int main ()
{
  std::string line;
  std::cin >> line;
  std::sort(std::begin(line), std::end(line));
  std::set<std::string> permutations;
  permutations.insert(line);
  while (std::next_permutation(std::begin(line), std::end(line)))
  {
    permutations.insert(line);
  }
  std::cout << permutations.size() << "\n";
  for (auto const& permutation : permutations) { std::cout << permutation << "\n"; }
  return 0;
}