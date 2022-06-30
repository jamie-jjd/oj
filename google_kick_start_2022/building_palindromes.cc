#include <iostream>
#include <numeric>
#include <vector>

int main ()
{
  std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
  uint64_t T; std::cin >> T;
  for (uint64_t x {}; x != T; ++x)
  {
    uint64_t N, Q; std::cin >> N >> Q;
    std::vector<std::vector<bool>> is_odd(26, std::vector<bool>(N + 1));
    for (uint64_t i {}; i != N; ++i)
    {
      char c; std::cin >> c;
      is_odd[c - 'A'][i + 1] = true;
    }
    for (uint64_t i {}; i != 26; ++i)
    {
      for (uint64_t j {1}; j <= N; ++j) { is_odd[i][j] = is_odd[i][j] ^ is_odd[i][j - 1]; }
    }
    uint64_t count {};
    while (Q--)
    {
      uint64_t L, R; std::cin >> L >> R;
      uint64_t count_odd {};
      for (uint64_t i {}; i != 26; ++i) { count_odd += is_odd[i][R] ^ is_odd[i][L - 1]; }
      auto is_even_length {((R - L) & 1) == 1};
      count += (is_even_length && (count_odd == 0)) || (!is_even_length && (count_odd == 1));
    }
    std::cout << "Case #" << x + 1 << ": " << count << "\n";
  }
  return 0;
}