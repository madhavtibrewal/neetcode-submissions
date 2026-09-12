class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0, h = n - 1;
        while(l < h){
            int m = l + (h - l) / 2;

            if(m + k < n && (x - arr[m] > arr[m + k] - x)){
                l = m + 1;
            }
            else{
                h = m;
            }
        }

        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};