#include <deque>
#include <iostream>
#include <tuple>
#include <vector>

int main ()
{
  uint64_t H, W;
  std::cin >> H >> W;
  std::vector<std::string> C(H);
  for (auto& row : C) { std::cin >> row; }
  std::deque<std::tuple<uint64_t, uint64_t, uint64_t>> queue;
  std::vector<std::vector<bool>> is_discovered(H, std::vector<bool>(W));
  std::array<uint64_t, 2> dr = {0, 1};
  std::array<uint64_t, 2> dc = {1, 0};
  is_discovered[0][0] = true;
  queue.emplace_back(0, 0, 1);
  uint64_t distance {};
  while (!queue.empty())
  {
    auto [r, c, d] {queue.front()}; queue.pop_front();
    distance = d;
    for (uint64_t i {}; i != 2; ++i)
    {
      if (r + dr[i] < H && c + dc[i] < W && !is_discovered[r + dr[i]][c + dc[i]] && C[r + dr[i]][c + dc[i]] != '#')
      {
        is_discovered[r + dr[i]][c + dc[i]] = true;
        queue.emplace_back(r + dr[i], c + dc[i], d + 1);
      }
    }
  }
  std::cout << distance << "\n";
  return 0;
}