#include <deque>
#include <iostream>
#include <vector>

void CalculateRootSumAndSubtreeSize
(
  std::vector<std::vector<uint64_t>> const& tree,
  std::vector<uint64_t>& subtree_sizes,
  std::vector<uint64_t>& distances
)
{
  std::vector<bool> is_visited(tree.size());
  std::vector<bool> is_forward(tree.size(), true);
  std::deque<uint64_t> stack;
  stack.push_back(0);
  while (!stack.empty())
  {
    auto from {stack.back()};
    is_visited[from] = true;
    if (is_forward[from])
    {
      is_forward[from] = false;
      for (auto to : tree[from])
      {
        if (!is_visited[to])
        {
          stack.push_back(to);
          distances[to] = distances[from] + 1;
        }
      }
      distances[0] += distances[from];
    }
    else
    {
      is_forward[from] = true;
      ++subtree_sizes[from];
      for (auto to : tree[from])
      {
        if (is_forward[to]) { subtree_sizes[from] += subtree_sizes[to]; }
      }
      stack.pop_back();
    }
  }
  return;
}

void CalculateDistances
(
  std::vector<std::vector<uint64_t>> const& tree,
  std::vector<uint64_t> const& subtree_sizes,
  std::vector<uint64_t>& distances
)
{
  std::vector<bool> is_visited(tree.size());
  std::deque<uint64_t> stack;
  stack.push_back(0);
  while (!stack.empty())
  {
    auto from {stack.back()}; stack.pop_back();
    is_visited[from] = true;
    for (auto to : tree[from])
    {
      if (!is_visited[to])
      {
        stack.push_back(to);
        distances[to] = distances[from] + tree.size() - subtree_sizes[to] * 2;
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
  std::vector<uint64_t> subtree_sizes(n);
  std::vector<uint64_t> distances(n);
  CalculateRootSumAndSubtreeSize(tree, subtree_sizes, distances);
  CalculateDistances(tree, subtree_sizes, distances);
  for (auto distance : distances) { std::cout << distance << " "; }
  std::cout << "\n";
  return 0;
}