class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int l = 1, r = x / 2;
        int res = 0;

        while(l <= r){
            int m = l + (r - l) / 2;
            long long sqr = (long long) m * m;
            if(sqr < x){
                l = m + 1;
                res = m;
            }
            else if(sqr > x){
                r = m - 1;
            }
            else{
                return m;
            }
        }
        return res;
    }
};