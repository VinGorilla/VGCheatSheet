// Palindrome Partitioning

// 1. Very stupid, Brute Force, TLE......shit
class Solution {
public:
    int minCut(string s) {
        int ret = INT_MAX;
        helper(s, 0, 0, ret);
        return ret;
    }
    
    void helper(string &s, int beg, int n, int &ret) {
        if(beg == s.size()) ret = min(ret, n-1);
        for(int i = beg; i < s.size(); ++i) {
            if(palindrome(s.substr(beg, i-beg+1))) {
                n++;
                helper(s, i+1, n, ret);
                n--;
            }
        }
    }
    
    bool palindrome(string s) {
        for(int i = 0; i <= s.size()/2; ++i)
            if(s[i] != s[s.size()-i-1]) return false;
        return true;
    }
};

// 2. WA becase it did not be able to return the optimal result, and we know that there is always not realistic to get the optimal result in real scene.
// Stupid though, it did make a breakthrough in solving the TLE problem... 

class Solution {
public:
    int minCut(string s) {
        int sum = 0;

        int n = s.size();
        int i = 0, j = n - 1;
        while(i <= j && i < n && j < n) {
            if(s[i] == s[j]) {
                int k = i, l = j;
                while(k <= l && s[k++] == s[l--]);
                if(k - l > 0 && s[k-1] == s[l+1]) { 
                    i = j+1;
                    j = n-1;
                    ++sum;
                } else {
                    --j;
                }
            }
            else --j;
        }
        
        return sum == 0 ? n-1 : sum-1;
    }
};