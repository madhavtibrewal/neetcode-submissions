class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        int low = 0, high = n - 1;
        vector<int> res;

        while(low < high){
            int mid = low + (high - low) / 2;

            if(arr[mid] >= x){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        int l = high - 1, r = high;
        while(r - l - 1 < k){
            if(r >= n || ( l >= 0 && arr[r] - x >= x - arr[l])){
                l--;
            }
            else {
                r++;
            }
        }

        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};