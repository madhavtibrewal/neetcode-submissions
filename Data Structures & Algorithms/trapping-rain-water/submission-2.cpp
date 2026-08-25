class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int lMax = height[0];
        int rMax = height[r];
        int res = 0;

        while(l <= r){
            int curr = 0;
            if(lMax <= rMax){
                curr = lMax - height[l];
                if(curr > 0){
                    res += curr;
                }
                lMax = max(lMax, height[l]);
                l++;
            }
            else{
                curr = rMax - height[r];
                if(curr > 0){
                    res += curr;
                }
                rMax = max(rMax, height[r]);
                r--;
            }
        }

        return res;
    }
};
