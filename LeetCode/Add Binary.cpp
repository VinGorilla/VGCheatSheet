// Add Binary

class Solution {
public:
    string addBinary(string a, string b) {
        int del = a.size() > b.size() ? a.size() - b.size() : b.size() - a.size();
        string fill(del, '0');
        if(a.size() < b.size()) a = fill + a;
        else  b = fill + b;
        string ret = "";
        int carry = 0;
        for(int i = a.size()-1; i >= 0; --i) {
            int x = (a[i] - '0') + (b[i] - '0') + carry;
            ret = (char)(x % 2 + '0') + ret;
            carry = x / 2;
        }
        while(carry > 0) {
            ret = (char)(carry % 2 + '0') + ret;
            carry /= 2;
        }
        return ret;
    }
};