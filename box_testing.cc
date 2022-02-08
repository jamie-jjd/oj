#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main ()
{
  uint64_t w {}, h {};
  while (std::cin >> w >> h)
  {
    std::vector<uint64_t> len;
    std::map<uint64_t, uint64_t> rank;
    len.push_back((w < h) ? w : h);
    len.push_back((w < h) ? h : w);
    rank[w] = rank[h] = 0;
    for (uint64_t i {1}; i != 6; ++i)
    {
      std::cin >> w >> h;
      len.push_back((w < h) ? w : h);
      len.push_back((w < h) ? h : w);
      rank[w] = rank[h] = 0;
    }
    uint64_t i {};
    for (auto it {std::begin(rank)}; it != std::end(rank); ++it) { std::get<1>(*it) = i++; }
    for (uint64_t i {}; i != 12; i += 2) { len[i / 2] = rank[len[i]] * 10 + rank[len[i + 1]]; }
    std::sort(std::begin(len), std::next(std::begin(len), 6));
    if
    (
      (len[0] == 0 && len[1] == 0 && len[2] == 0 && len[3] == 0 && len[4] == 0 && len[5] == 0) ||
      (len[0] == 0 && len[1] == 0 && len[2] == 1 && len[3] == 1 && len[4] == 1 && len[5] == 1) ||
      (len[0] == 1 && len[1] == 1 && len[2] == 1 && len[3] == 1 && len[4] == 11 && len[5] == 11) ||
      (len[0] == 1 && len[1] == 1 && len[2] == 2 && len[3] == 2 && len[4] == 12 && len[5] == 12)
    )
    { std::cout << "POSSIBLE\n"; }
    else
    { std::cout << "IMPOSSIBLE\n"; }
  }
  return 0;
}