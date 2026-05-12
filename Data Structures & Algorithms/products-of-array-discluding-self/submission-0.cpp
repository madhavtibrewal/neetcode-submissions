class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*[1, 2, 4, 6] => [1, 1, 2, 8]
                        [48,24,6,1]
                        48 24 12 8*/
        int n = nums.size();

        vector<int> pre(n, 1);
        vector<int> post(n, 1);
        vector<int> res(n);

        for(int i = 1; i < n; i++){
            pre[i] = pre[i - 1] * nums[i - 1];
            post[n - i - 1] = post[n - i] * nums[n - i];
        }

        for(int i = 0; i < n; i++){
            res[i] = pre[i] * post[i];
        }

        return res;
    }
};
