/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;
        int count = 0, res = 0;

        for(auto &interval : intervals){
            start.push_back(interval.start);
            end.push_back(interval.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int s = 0, e = 0;

        while(s < start.size()){
            if(start[s] < end[e]){
                s++;
                count++;
            }
            else{
                e++;
                count--;
            }
            res = max(count, res);
        }

        return res;
    }
};
