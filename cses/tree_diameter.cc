#include <deque>
#include <iostream>
#include <utility>
#include <vector>

std::pair<uint64_t, uint64_t> BFS (std::vector<std::vector<uint64_t>> const& tree, uint64_t source)
{
  std::pair<uint64_t, uint64_t> pair;
  std::vector<bool> is_discovered(tree.size());
  std::deque<std::pair<uint64_t, uint64_t>> queue;
  queue.emplace_back(source, 0);
  is_discovered[source] = true;
  while (!queue.empty())
  {
    pair = queue.front(); queue.pop_front();
    for (auto const to : tree[std::get<0>(pair)])
    {
      if (!is_discovered[to])
      {
        is_discovered[to] = true;
        queue.emplace_back(to, std::get<1>(pair) + 1);
      }
    }
  }
  return pair;
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
  std::cout << std::get<1>(BFS(tree, std::get<0>(BFS(tree, 0)))) << "\n";
  return 0;
}