#include <iostream>
#include <vector>

int main ()
{
  uint64_t N;
  std::cin >> N;
  std::vector<uint64_t> h(N);
  for (auto& h_i : h) { std::cin >> h_i; }
  std::vector<uint64_t> cost(N);
  cost[1] = std::llabs(h[1] - h[0]);
  for (uint64_t i {2}; i != N; ++i)
  {
    cost[i] = std::min(cost[i - 1] + std::llabs(h[i] - h[i - 1]), cost[i - 2] + std::llabs(h[i] - h[i - 2]));
  }
  std::cout << cost[N - 1] << "\n";
  return 0;
}