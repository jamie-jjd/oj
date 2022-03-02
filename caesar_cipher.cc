#include <iostream>

int main ()
{
  std::string S, T;
  std::cin >> S >> T;
  int64_t K {(26 + (T[0] - 'a') - (S[0] - 'a')) % 26};
  bool is_possible {true};
  for (uint64_t i {1}; i != S.size() && is_possible; ++i) { is_possible = (((S[i] - 'a') + K) % 26 == (T[i] - 'a')); }
  std::cout << ((is_possible) ? "Yes" : "No") << "\n";
  return 0;
}