#include <bits/stdc++.h>
#include <cstring>

class Solution {
public:
  int dp[1000][1000] = {{}};
  int ret = 0;
  int start = 0;
  int size = 0;
  std::string longestPalindrome(std::string s) {
    for (int i = 0; i < s.size(); i++) {
      dp[i][i] = 1;
      if (i + 1 < s.size() && s[i] == s[i + 1]) {
        dp[i][i + 1] = 2;
        if (ret < dp[i][i + 1]) {
          ret = dp[i][i + 1];
          start = i;
          size = 2;
        }
      }
    }

    for (int i = 2; i < s.size(); i++) {
      for (int j = 0; j + i < s.size(); j++) {
        if (s[j] == s[j + i] && dp[j + 1][j + i - 1] > 0) {
          dp[j][j + i] = dp[j + 1][j + i - 1] + 2;
        } else {
          dp[j][j + i] = 0;
        }
        if (ret < dp[j][j + i]) {
          ret = dp[j][j + i];
          start = j;
          size = i;
        }
      }
    }
    return s.substr(start, size);
  }
};