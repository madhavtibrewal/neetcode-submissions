class CountSquares {
private:
    map<pair<int,int>, int> ptsCount;
    vector<pair<int, int>> pts;

public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        ptsCount[{point[0], point[1]}]++;
        pts.push_back({point[0], point[1]});
    }
    
    int count(vector<int> point) {
        int res = 0;
        int px = point[0], py = point[1];

        for(auto &[x, y] : pts){
            if(abs(px - x) != abs(py - y) || x == px || y == py){
                continue;
            }
            res += ptsCount[{px, y}] * ptsCount[{x, py}];
        }
        return res;
    }
};
