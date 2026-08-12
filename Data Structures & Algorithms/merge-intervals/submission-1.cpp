class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        

        for(int i = 1; i < intervals.size(); i++){
            int lastEnd = res.back()[1];
            if(lastEnd >= intervals[i][0]){
                res.back()[1] = max(intervals[i][1], lastEnd);
            }
            else{
                res.push_back({intervals[i][0], intervals[i][1]});
            }
        }

        return res;
    }
};
