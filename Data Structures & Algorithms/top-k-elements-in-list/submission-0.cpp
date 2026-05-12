class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        vector<pair<int, int>> freqPair;
        vector<int> res;

        for(int i : nums){
            freq[i]++;
        }

        for(auto& [n, f] : freq){
            freqPair.push_back({f, n});
        }

        sort(freqPair.begin(), freqPair.end());
        int i = freqPair.size() - 1;
        
        while(k != 0){
            res.push_back(freqPair[i].second);
            i--;
            k--;
        }

        return res;
    }
};
