// Trapping Rain Water

class Solution {
public:
    int trap(int a[], int n) {
        if(n < 3) return 0;
        int l = 0, h = n-1, t = 0;
        int water = 0;
        while(l < h) {
            if(a[l] < a[h]) {
                t = a[l++];
                while(l < h && a[l] <= t) {water += t - a[l]; ++l;}
            } else {
                t = a[h--];
                while(l < h && a[h] <= t) {water += t - a[h]; --h;}
            }
        }
        return water;
    }
};