// Palindrome Partitioning

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> tmp;
        helper(s, 0, tmp, ret);
        return ret;
    }
    
    void helper(string s, int beg, vector<string> tmp, vector<vector<string>> &ret) {
        if(beg == s.size()) ret.push_back(tmp);
        for(int i = beg; i < s.size(); ++i) {
            string t = s.substr(beg, i-beg+1);
            if(palindrome(t)) {
                tmp.push_back(t);
                helper(s, i+1, tmp, ret);
                tmp.pop_back();
            }
        }
    }
    
    bool palindrome(string s) {
        for(int i = 0; i <= s.size()/2; ++i) {
            if(s[i] != s[s.size()-i-1]) return false;
        }
        return true;
    }
};