#include <bits/stdc++.h>

class Solution {
public:
  std::string intToRoman(int num) {
    std::vector<int> nums;
    while (num) {
      nums.push_back(num % 10);
      num /= 10;
    }
    std::string ret;
    for (int i = nums.size() - 1; i >= 0; i--) {
      int n = nums[i];
      if (n == 4) {
        if (i == 0) {
          ret += "IV";
        } else if (i == 1) {
          ret += "XL";
        } else if (i == 2) {
          ret += "CD";
        }
      } else if (n == 9) {
        if (i == 0) {
          ret += "IX";
        } else if (i == 1) {
          ret += "XC";
        } else if (i == 2) {
          ret += "CM";
        }
      } else {
        if (n >= 5) {
          if (i == 0) {
            ret += "V";
          } else if (i == 1) {
            ret += "L";
          } else if (i == 2) {
            ret += "D";
          }
          n -= 5;
        }
        for (int j = 0; j < n; j++) {
          if (i == 0) {
            ret += "I";
          } else if (i == 1) {
            ret += "X";
          } else if (i == 2) {
            ret += "C";
          } else if (i == 3) {
            ret += "M";
          }
        }
      }
    }
    return ret;
  }
};