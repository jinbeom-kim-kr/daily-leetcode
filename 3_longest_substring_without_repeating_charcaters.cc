#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
       std::map<int, int> hash;
       int i = 0;
       int ret = 0;
       int start = 0;
       for (const auto& c : s) {
            auto res = hash.find(c);
            if (res == hash.end()) {
                hash.insert({c, i});
            } else {
                if (start <= res->second) {
                    start = res->second + 1;
                }
                res->second = i;
            }
            ret = std::max(ret, i - start + 1);
            i++;
       }
       return ret;
    }
};