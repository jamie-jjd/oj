#include <deque>
#include <iostream>
#include <utility>
#include <vector>

uint64_t FindOneEnd (std::vector<std::vector<uint64_t>> const& tree)
{
  uint64_t from {};
  std::vector<bool> is_discovered(tree.size());
  std::deque<uint64_t> queue;
  is_discovered[0] = true;
  queue.emplace_back(from);
  while (!queue.empty())
  {
    from = queue.front(); queue.pop_front();
    for (auto const to : tree[from])
    {
      if (!is_discovered[to])
      {
        is_discovered[to] = true;
        queue.emplace_back(to);
      }
    }
  }
  return from;
}

uint64_t CalculateDistanceFromOneEnd
(
  std::vector<std::vector<uint64_t>> const& tree,
  std::vector<uint64_t>& distance,
  uint64_t from
)
{
  std::vector<bool> is_discovered(tree.size());
  std::deque<uint64_t> queue;
  is_discovered[from] = true;
  queue.emplace_back(from);
  while (!queue.empty())
  {
    from = queue.front(); queue.pop_front();
    for (auto const to : tree[from])
    {
      if (!is_discovered[to])
      {
        is_discovered[to] = true;
        distance[to] = distance[from] + 1;
        queue.emplace_back(to);
      }
    }
  }
  return from;
}

void CalculateDistanceFromOtherEnd
(
  std::vector<std::vector<uint64_t>> const& tree,
  std::vector<uint64_t>& distance,
  uint64_t from
)
{
  std::vector<bool> is_discovered(tree.size());
  std::deque<std::pair<uint64_t, uint64_t>> queue;
  is_discovered[from] = true;
  queue.emplace_back(from, 0);
  while (!queue.empty())
  {
    auto [from, d] {queue.front()}; queue.pop_front();
    for (auto const to : tree[from])
    {
      if (!is_discovered[to])
      {
        is_discovered[to] = true;
        if (distance[to] < d + 1) { distance[to] = d + 1; }
        queue.emplace_back(to, d + 1);
      }
    }
  }
  return;
}

int main ()
{
  uint64_t n {};
  std::cin >> n;
  std::vector<std::vector<uint64_t>> tree(n);
  for (uint64_t i {}; i != n - 1; ++i)
  {
    uint64_t from {}, to {};
    std::cin >> from >> to;
    tree[from - 1].push_back(to - 1);
    tree[to - 1].push_back(from - 1);
  }
  std::vector<uint64_t> distance(n);
  CalculateDistanceFromOtherEnd(tree, distance, CalculateDistanceFromOneEnd(tree, distance, FindOneEnd(tree)));
  for (auto d : distance) { std::cout << d << " "; }
  std::cout << "\n";
  return 0;
}