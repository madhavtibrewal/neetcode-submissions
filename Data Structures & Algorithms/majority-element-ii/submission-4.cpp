class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> res;

        for(int i : nums){
            freq[i]++;
            if(freq.size() > 2){
                unordered_map<int, int> newFreq;
                for(auto& [key, value] : freq){
                    if(value > 1){
                        newFreq.insert({key, value - 1});
                    }
                }
                freq = newFreq;
            }
        }

        for(auto& [key, value] : freq){
            int frequency = 0;
            for(int i : nums){
                if(key == i) frequency++;
            }
            if( frequency > nums.size() / 3){
                res.push_back(key);
            }
        }
        return res;

    }
};