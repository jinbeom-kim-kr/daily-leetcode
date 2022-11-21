#include <bits/stdc++.h>

class Solution {
public:
  bool isMatch(std::string s, std::string p) {
    if (s.empty() && p.empty()) return true;
    if (p.empty()) return false;
    if (p.size() > 1 && p[1] == '*') {
      return isMatch(s, p[0] + p.substr(2)) ? true : isMatch(s, p.substr(2));
    }
    if (p.front() == '.') {
        return isMatch(s.substr(1), p.substr(1));
    }
    if (p.front() != s.front()) return false;
    return isMatch(s.substr(1), p.substr(1));
  }
};