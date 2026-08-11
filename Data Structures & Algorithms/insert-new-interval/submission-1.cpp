class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        for(int i = 0; i < n; i++){
            if(intervals[i][0] > newEnd){
                res.push_back({newStart, newEnd});
                copy(intervals.begin() + i, intervals.end(), back_inserter(res));
                return res;

            }
            else if(intervals[i][1] < newStart){
                res.push_back(intervals[i]);
            }
            else{
                newStart = min(newStart, intervals[i][0]);
                newEnd = max(newEnd, intervals[i][1]);
            }
        }
        res.push_back({newStart, newEnd});
        return res;
    }
};
