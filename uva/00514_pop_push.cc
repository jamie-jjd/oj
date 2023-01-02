#include <iostream>
#include <vector>

int main ()
{
  uint64_t N {};
  while (std::cin >> N && N)
  {
    std::vector<uint64_t> a(N);
    while (std::cin >> a[0] && a[0])
    {
      for (uint64_t i {1}; i != N; ++i) { std::cin >> a[i]; }
      std::vector<uint64_t> stack;
      auto it {std::begin(a)};
      uint64_t i {};
      while (i++ != N)
      {
        stack.push_back(i);
        while (it != std::end(a) && !stack.empty() && *it == stack.back())
        {
          ++it;
          stack.pop_back();
        }
      }
      std::cout << ((stack.empty()) ? "Yes" : "No") << "\n";
    }
    std::cout << "\n";
  }
  return 0;
}