class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;
        int n = s.size();
        for(int i = 0; i < n; i++){
            lastIndex[s[i]] = i;
        } 

        int start = 0, end = 0;
        vector<int> partitions;

        for(int i = 0; i < n; i++){
            end = max(end,lastIndex[s[i]]);

            if(i == end){
                partitions.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return partitions;
    }
};
