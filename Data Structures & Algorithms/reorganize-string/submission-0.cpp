class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> maxHeap;
        vector<int> freq(26, 0);

        for(char&c : s){
            freq[c - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                maxHeap.push({freq[i], 'a' + i});
            }
        }

        string res = "";
        pair<int, char> prev = {0, ' '};
        while(!maxHeap.empty() || prev.first > 0){
            if(prev.first > 0 && maxHeap.empty()){
                return "";
            }

            auto [cnt, ch] = maxHeap.top();
            maxHeap.pop();
            cnt--;
            res += ch;

            if(prev.first > 0){
                maxHeap.push(prev);
            }

            prev = {cnt, ch};
        }

        return res;
    }
};