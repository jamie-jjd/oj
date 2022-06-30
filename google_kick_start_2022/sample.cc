#include <iostream>

int main ()
{
  std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
  uint64_t T; std::cin >> T;
  for (uint64_t x {}; x != T; ++x)
  {
    uint64_t N, M; std::cin >> N >> M;
    uint64_t C {};
    for (uint64_t i {}, C_i; i != N; ++i) { std::cin >> C_i; C += C_i; }
    std::cout << "Case #" << (x + 1) << ": " << C % M << "\n";
  }
  return 0;
}