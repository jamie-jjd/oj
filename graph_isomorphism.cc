#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

int main ()
{
  uint64_t N, M;
  std::cin >> N >> M;
  std::vector<std::set<uint64_t>> G(N), H(N);
  for (uint64_t i {}; i != M; ++i)
  {
    uint64_t from, to;
    std::cin >> from >> to;
    G[from - 1].insert(to - 1);
    G[to - 1].insert(from - 1);
  }
  for (uint64_t i {}; i != M; ++i)
  {
    uint64_t from, to;
    std::cin >> from >> to;
    H[from - 1].insert(to - 1);
    H[to - 1].insert(from - 1);
  }
  std::vector<uint64_t> P(N);
  std::iota(P.begin(), P.end(), 0);
  bool is_isomorphic {};
  do
  {
    is_isomorphic = true;
    for (uint64_t from {}; from != N; ++from)
    {
      for (auto to : G[from])
      {
        if (H[P[from]].count(P[to]) == 0)
        {
          is_isomorphic = false;
          break;
        }
      }
    }
  }
  while (std::next_permutation(P.begin(), P.end()) && !is_isomorphic);
  std::cout << ((is_isomorphic) ? "Yes" : "No") << "\n";
  return 0;
}