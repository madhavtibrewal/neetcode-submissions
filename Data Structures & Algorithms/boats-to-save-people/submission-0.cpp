class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> count(limit + 1, 0);
        int res = 0;

        for(int w : people){
            count[w]++;
        }
        int idx = 0;
        int i = 1;

        while(idx < people.size()){
            while(count[i] == 0) i++;
            people[idx++] = i;
            count[i]--;
        }
        int l = 0;
        int r = people.size() - 1;
        while(l <= r){
            if(people[l] + people[r] <= limit){
                l++;
            }
            r--;
            res++;
        }
        return res;
    }
};  