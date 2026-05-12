class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     unordered_set<int> numSet(nums.begin(), nums.end());
     int maxi = 0;
     
     for(int num : nums){
        if(numSet.find(num - 1) == numSet.end()){
            int start = num + 1;
            int count = 1;
            while(numSet.find(start) != numSet.end()){
                start++;
                count++;
            }
            maxi = max(maxi, count);
        }
     }

     return maxi;
    }
};
