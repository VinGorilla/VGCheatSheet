// 3Sum Closest

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size() < 3) return 0;
        sort(num.begin(), num.end());
        int minDist = INT_MAX;
        int n = num.size();
        int ret = 0;
        for(int i = 0; i < n-2; ++i) {
            int k = i+1;
            int l = n-1;
            while(k < l) {
                int tsum = num[i] + num[k] + num[l];
                int tdist = tsum - target;
                if(tdist == 0) return target;
                if(abs(tdist) < minDist) {                    
                    if(tsum < target) k++;
                    else l--;
                    minDist = abs(tdist); 
                    ret = tsum;
                } else {
                    if(tsum < target) k++;
                    else l--;
                }
            }
        }
        return ret;
    }
};