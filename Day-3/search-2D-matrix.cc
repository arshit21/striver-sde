class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int lowRow = 0;
        int highRow = m-1;
        int searchRow = -1;
        if(target > matrix[m-1][n-1]){
            return false;
        }
        if(target < matrix[0][0]){
            return false;
        }
        if(m == 1){
            int r = n-1;
            int l = 0;
            while(l <= r){
                int mid = (r+l)/2;
                if(target < matrix[0][mid]){
                    r = mid-1;
                }
                else if(target > matrix[0][mid]){
                    l = mid+1;
                }
                else{
                    return true;
                }
            }
            return false;
        }
        while(searchRow < 0){
            int mid = (highRow + lowRow)/2;
            if(target < matrix[mid][0]){
                if(target >= matrix[mid-1][0]){
                    searchRow = mid-1;
                }
                else{
                    highRow = mid-1;
                }
            }
            else if(target > matrix[mid][0]){
                if(mid == m-1){
                    searchRow = mid;
                }
                else if(target < matrix[mid+1][0]){
                    searchRow = mid;
                }
                else{
                    lowRow = mid+1;
                }
            }
            else{
                return true;
            }
        }

        int lowFinal = 0;
        int highFinal = n-1;
        while(lowFinal <= highFinal){
            int mid =(highFinal+lowFinal)/2;
            if(target < matrix[searchRow][mid]){
                highFinal = mid-1;
            }
            else if(target > matrix[searchRow][mid]){
                lowFinal = mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};