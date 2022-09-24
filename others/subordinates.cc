#include <iostream>
#include <deque>
#include <utility>
#include <vector>

void DFS
(
  std::vector<std::vector<uint64_t>> const& tree,
  std::vector<uint64_t>& subtree_size
)
{
  std::deque<std::pair<uint64_t, bool>> stack;
  stack.emplace_back(0, true);
  while (!stack.empty())
  {
    auto& from {std::get<0>(stack.back())};
    auto& is_forward {std::get<1>(stack.back())};
    if (is_forward)
    {
      is_forward = false;
      for (auto& to : tree[from]) { stack.emplace_back(to, true); }
    }
    else
    {
      for (auto& to : tree[from]) { subtree_size[from] += subtree_size[to] + 1; }
      stack.pop_back();
    }
  }
  return;
}

int main ()
{
  uint64_t n {};
  std::cin >> n;
  std::vector<std::vector<uint64_t>> tree(n);
  std::vector<uint64_t> subtree_size(n);
  for (uint64_t i {1}; i != n; ++i)
  {
    uint64_t parent {};
    std::cin >> parent;
    tree[parent - 1].push_back(i);
  }
  DFS(tree, subtree_size);
  for (uint64_t i {}; i != n; ++i)
  {
    std::cout << subtree_size[i] << ((i != n - 1) ? " " : "\n");
  }
  return 0;
}