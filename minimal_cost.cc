#include <iostream>
#include <queue>

int main ()
{
  uint64_t N {};
  while (std::cin >> N && N)
  {
    std::priority_queue<uint64_t, std::vector<uint64_t>, std::greater<uint64_t>> min_heap;
    for (uint64_t i {}, x {}; i != N; ++i)
    {
      std::cin >> x;
      min_heap.push(x);
    }
    uint64_t cost {};
    while (min_heap.size() != 1)
    {
      auto min {min_heap.top()}; min_heap.pop();
      auto second_min {min_heap.top()}; min_heap.pop();
      auto sum {min + second_min};
      min_heap.push(sum);
      cost += sum;
    }
    std::cout << cost << "\n";
  }
  return 0;
}