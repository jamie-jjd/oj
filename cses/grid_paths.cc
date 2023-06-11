#include <array>
#include <iostream>
#include <string>

using namespace std;

static constexpr int PATH_SIZE {48};
static constexpr int GRID_SIZE {9};
static constexpr int DIR_SIZE {4};

uint64_t
explore(
  array<array<bool, GRID_SIZE>, GRID_SIZE> &G,
  int r,
  int c,
  array<int, PATH_SIZE> const &D,
  int i
) {
  static int const dr[] {1, -1, 0, 0};
  static int const dc[] {0, 0, -1, 1};
  if (
    (G[r][c - 1] and G[r][c + 1] and not G[r - 1][c] and not G[r + 1][c]) or
    (not G[r][c - 1] and not G[r][c + 1] and G[r - 1][c] and G[r + 1][c])
  ) { return 0; }
  if (r == 7 and c == 1) { return (i == PATH_SIZE); }
  if (i == PATH_SIZE) { return 0; }
  uint64_t S {};
  G[r][c] = true;
  if (D[i] < DIR_SIZE) {
    auto nr {r + dr[D[i]]}, nc {c + dc[D[i]]};
    if (not G[nr][nc]) { S += explore(G, nr, nc, D, i + 1); }
  }
  else {
    for (int j {}; j < DIR_SIZE; ++j) {
      auto nr {r + dr[j]}, nc {c + dc[j]};
      if (G[nr][nc]) { continue; }
      S += explore(G, nr, nc, D, i + 1);
    }
  }
  G[r][c] = false;
  return S;
}
 
int
main() {
  string P; getline(cin, P);
  array<int, PATH_SIZE> D {};
  for (int i {}; i < PATH_SIZE; ++i) {
    if (P[i] == 'D') { D[i] = 0; }
    else if (P[i] == 'U') { D[i] = 1; }
    else if (P[i] == 'L') { D[i] = 2; }
    else if (P[i] == 'R') { D[i] = 3; }
    else { D[i] = DIR_SIZE; }
  }
  array<array<bool, GRID_SIZE>, GRID_SIZE> G {};
  for (int i {}; i < GRID_SIZE; ++i) {
    G[0][i] = G[i][0] = true;
    G[GRID_SIZE - 1][i] = G[i][GRID_SIZE - 1] = true;
  }
  cout << explore(G, 1, 1, D, 0) << "\n";
  return 0;
}

