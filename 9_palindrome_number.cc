#include <bits/stdc++.h>

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    std::string s;
    while (x > 0) {
      s += x % 10;
      x /= 10;
    }
    int lo = 0;
    int hi = s.size() - 1;
    while (lo <= hi) {
      if (s[lo] != s[hi])
        return false;
      lo++;
      hi--;
    }
    return true;
  }
};