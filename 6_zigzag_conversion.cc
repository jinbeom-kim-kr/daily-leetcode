#include <bits/stdc++.h>
#include <iterator>

class Solution {
public:
  std::string convert(std::string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    std::string ret;
    std::vector<int> visited(s.size(), 0);
    int gap = numRows * 2 - 2;
    for (int i = 0; i < numRows; i++) {
      int j = i;
      if (j < s.size() && !visited[j]) {
        ret += s[j];
        visited[j] = true;
      }
      while (j < s.size()) {
        int first = j + gap - (i * 2);
        int second = j + gap;
        if (first < s.size() && !visited[first]) {
          ret += s[first];
          visited[first] = true;
        }
        if (second < s.size() && !visited[second]) {
          ret += s[second];
          visited[second] = true;
        }
        j = second;
      }
    }
    return ret;
  }
};