#include <iostream>
#include <queue>
#include <vector>

int main ()
{
  std::priority_queue<uint64_t, std::vector<uint64_t>, std::less<uint64_t>> max_heap;
  std::priority_queue<uint64_t, std::vector<uint64_t>, std::greater<uint64_t>> min_heap;
  uint64_t i {}, X;
  while (std::cin >> X)
  {
    if (i & 1)
    {
      if (X < max_heap.top())
      {
        max_heap.push(X);
        min_heap.push(max_heap.top());
        max_heap.pop();
      }
      else { min_heap.push(X); }
      std::cout << (max_heap.top() + min_heap.top()) / 2 << "\n";
    }
    else
    {
      if (!max_heap.empty() && X > max_heap.top())
      {
        min_heap.push(X);
        max_heap.push(min_heap.top());
        min_heap.pop();
      }
      else { max_heap.push(X); }
      std::cout << max_heap.top() << "\n";
    }
    ++i;
  }
  return 0;
}