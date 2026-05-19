class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int maxStone = *max_element(stones.begin(), stones.end());

        vector<int> bucket(maxStone + 1, 0);

        for(int s : stones){
            bucket[s]++;
        }

        int first = maxStone;
        int second = first - 1;

        while(first > 0){
            if(bucket[first] % 2 == 0){
                bucket[first] = 0;
                first--;
                continue;
            }

            second = first - 1;
            while(second > 0 && bucket[second] == 0) second--;

            if(second == 0) return first;

            bucket[first]--;
            bucket[second]--;
            bucket[first - second]++;
            first = max(first - second, second);
        }

        return first;
    }
};
