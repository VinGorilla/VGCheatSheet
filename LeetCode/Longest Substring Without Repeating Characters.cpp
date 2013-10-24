// Longest Substring Without Repeating Characters 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2) return s.size();
        unordered_map<int, bool> map;
        int l = 0, h = 1;
        map[s[l]] = true;
        int ret = 0;
        while(h < s.size()) {
            if(map[s[h]]) {
                ret = max(ret, h - l);
                while(s[l] != s[h]) {map[s[l]] = false; ++l;}
                ++l;
                ++h;
            } else {
                map[s[h]] = true;
                ++h;
            }
        }
        ret = max(ret, h - l);
        return ret;
    }
};