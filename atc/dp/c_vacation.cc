#include <algorithm>
#include <iostream>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  uint64_t N; cin >> N;
  uint64_t ha, hb, hc; cin >> ha >> hb >> hc;
  while (--N) {
    uint64_t a, b, c; cin >> a >> b >> c;
    uint64_t ha_ {a + max(hb, hc)};
    uint64_t hb_ {b + max(ha, hc)};
    uint64_t hc_ {c + max(ha, hb)};
    ha = ha_; hb = hb_; hc = hc_;
  }
  cout << max(ha, max(hb, hc));
  return 0;
}
