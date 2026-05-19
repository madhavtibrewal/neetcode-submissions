class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> keyStore;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyStore[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(keyStore.find(key) == keyStore.end()){
            return "";
        }

        auto& values = keyStore[key];

        int l = 0;
        int r = values.size() - 1;
        string result = "";

        while(l <= r){
            int m = l + ((r - l) / 2);

            if(values[m].second <= timestamp){
                result = values[m].first;
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }

        return result;
    }
};
