class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        int lastEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(lastEnd > start){
                count++;
            }
            else{
                lastEnd = end;
            }
        }

        return count;
    }
};
