class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size() - 1;
        int COLS = matrix[0].size();

        while(left <= right){
            int mid = left + ((right - left) / 2);

            if(matrix[mid][0] > target){
                right = mid - 1;
            }
            else if(matrix[mid][COLS - 1] < target){
                left = mid + 1;
            }
            else{
                break;
            }
        }

        left = (left + right) / 2;

        int l = 0, r = matrix[left].size() - 1;

        while(l <= r){
            int mid = l + ((r - l) / 2);

            if(matrix[left][mid] > target){
                r = mid - 1;
            }
            else if(matrix[left][mid] < target){
                l = mid + 1;
            }
            else{
                return true;
            }
        }


        return false;
    }
};
