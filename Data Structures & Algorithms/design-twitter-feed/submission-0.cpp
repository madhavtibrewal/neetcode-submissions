class Twitter {
private:
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, set<int>> followMap;
    int count;
    
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int, int>> maxHeap;
        vector<int> res;

        followMap[userId].insert(userId);
        for(auto& followerId : followMap[userId]){
            if(tweets.count(followerId)){
                int index = tweets[followerId].size() - 1;
                auto& [count, tweetId] = tweets[followerId][index];
                maxHeap.push({count, tweetId, followerId, index - 1});
            }
        }

        while(!maxHeap.empty() && res.size() < 10){
            auto [count, tweetId, followerId, index] = maxHeap.top();
            maxHeap.pop();
            res.push_back(tweetId);
            if(index >= 0){
                auto& [count, tweetId] = tweets[followerId][index];
                maxHeap.push({count, tweetId, followerId, index - 1});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
