#include <iostream>
#include <deque>

int main ()
{
  uint64_t n {};
  std::string line;
  std::getline(std::cin, line);
  n = std::stoull(line);
  while (n--)
  {
    std::getline(std::cin, line);
    std::deque<char> stack;
    bool is_balanced {true};
    auto it {std::begin(line)};
    while (it != std::end(line))
    {
      if (*it == '[' || *it == '(')
      {
        stack.push_back(*it);
      }
      else if (*it == ']')
      {
        if (stack.empty() || stack.back() != '[') { break; }
        stack.pop_back();
      }
      else if (*it == ')')
      {
        if (stack.empty() || stack.back() != '(') { break; }
        stack.pop_back();
      }
      ++it;
    }
    std::cout << ((stack.empty() && it == std::end(line)) ? "Yes" : "No") << "\n";
  }
  return 0;
}