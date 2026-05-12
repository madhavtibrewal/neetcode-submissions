class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        vector<vector<int>> bucket(n + 1);
        vector<int> res;
        for(int i : nums){
            freq[i]++;
        }
        /*for(auto& [n, f] : freq){
            freqPair.push_back({f, n});
        }
        sort(freqPair.begin(), freqPair.end());
        int i = freqPair.size() - 1;
        while(k != 0){
            res.push_back(freqPair[i].second);
            i--;
            k--;
        }*/

        for(const auto& [n, f] : freq){
            bucket[f].push_back(n);
        }

        for(int i = n; i >= 0; i--){
            for(int num : bucket[i]){
                res.push_back(num);
                if(res.size() == k){
                    return res;
                }
            }
        }
        return res;
    }
};
