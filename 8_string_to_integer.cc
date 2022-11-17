#include <bits/stdc++.h>
#include <climits>

class Solution {
public:
  int myAtoi(std::string s) {
    int worker = 0;
    while (worker < s.size()) {
      if (s[worker] != ' ')
        break;
      worker++;
    }
    bool is_sigend = true;
    if (worker < s.size()) {
      if (s[worker] == '-') {
        is_sigend = false;
        worker++;
      } else if (s[worker] == '+') {
        worker++;
      }
    }
    while (worker < s.size()) {
      if (s[worker] != '0')
        break;
      worker++;
    }
    int ret = 0;
    while (worker < s.size() && s[worker] >= '0' && s[worker] <= '9') {
      if (is_sigend &&
          ((ret > 214748364) || (ret == 214748364 && (s[worker] - '0') >= 7))) {
        return INT_MAX;
      } else if (!is_sigend && ((ret > 214748364) ||
                                (ret == 214748364 && (s[worker] - '0') >= 8))) {
        return INT_MIN;
      }
      ret = ret * 10 + (s[worker] - '0');
      worker++;
    }
    return ret * (is_sigend ? 1 : -1);
  }
};