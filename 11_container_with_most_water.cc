#include <bits/stdc++.h>

class Solution {
public:
  int maxArea(std::vector<int> &height) {
    int lo = 0;
    int hi = height.size() - 1;
    int ret = 0;
    while (lo < hi) {
      int h = (hi - lo);
      ret = std::max(ret, h * std::min(height[lo], height[hi]));
    //   std::cout << ret << " " << lo << " " << hi << std::endl;
      if (height[lo] < height[hi])
        lo++;
      else
        hi--;
    }
    return ret;
  }
};