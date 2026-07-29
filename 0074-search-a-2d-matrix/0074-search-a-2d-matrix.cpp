class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = -1;

        int s = 0, e = rows - 1;

        while(s <= e){

            int mid = s + (e-s)/2;

            if(target >= matrix[mid][0] &&
               target <= matrix[mid][cols-1]){
                row = mid;
                break;
            }

            else if(target < matrix[mid][0])
                e = mid-1;
            else
                s = mid+1;
        }

        if(row == -1)
            return false;

        s = 0;
        e = cols-1;

        while(s <= e){

            int mid = s + (e-s)/2;

            if(matrix[row][mid] == target)
                return true;

            else if(matrix[row][mid] < target)
                s = mid+1;
            else
                e = mid-1;
        }

        return false;
    }
};