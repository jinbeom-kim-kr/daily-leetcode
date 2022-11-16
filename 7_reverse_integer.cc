#include <bits/stdc++.h>
#include <climits>

class Solution {
public:
  int reverse(int x) {
    std::int64_t origin = x;
    bool is_sigend = origin > 0;
    if (!is_sigend) {
      origin *= -1;
    }
    std::int64_t ret = 0;
    while (origin > 0) {
      ret *= 10;
      ret += origin % 10;
      origin /= 10;
    }
    if (ret >= INT_MAX)
      return 0;
    if (!is_sigend) {
      ret *= -1;
    }
    return ret;
  }
};