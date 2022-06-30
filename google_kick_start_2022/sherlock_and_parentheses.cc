#include <iostream>

int main ()
{
  std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
  uint64_t T; std::cin >> T;
  for (uint64_t x {}; x != T; ++x)
  {
    uint64_t L, R; std::cin >> L >> R;
    auto N {std::min(L, R)};
    std::cout << "Case #" << (x + 1) << ": " << N * (N + 1) / 2 << "\n";
  }
  return 0;
}