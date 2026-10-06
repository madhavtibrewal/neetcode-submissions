class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;

        if(a > 0) maxHeap.push({a, 'a'});
        if(b > 0) maxHeap.push({b, 'b'});
        if(c > 0) maxHeap.push({c, 'c'});

        string res = "";

        while(!maxHeap.empty()){
            auto [cnt1, ch1] = maxHeap.top();
            maxHeap.pop();  

            int n = res.size();

            if(n > 1 && res[n - 1] == ch1 && res[n - 2] == ch1){
                if(maxHeap.empty()) break;

                auto [cnt2, ch2] = maxHeap.top();
                res += ch2;
                maxHeap.pop();
                cnt2--;

                if(cnt2 > 0) maxHeap.push({cnt2, ch2});
                maxHeap.push({cnt1, ch1});
            }
            else{
                res += ch1;
                cnt1--;
                if(cnt1 > 0) maxHeap.push({cnt1,ch1});
            }
        }

        return res;

    }
};