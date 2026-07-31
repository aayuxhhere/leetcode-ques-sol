class Solution {
public:
    int maxelt(vector<vector<int>>& mat, int n, int col){
        int index = -1;
        int maxval = -1;
        for(int i = 0; i<n; i++){
            if(mat[i][col] > maxval){
                maxval = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int s = 0;
        int e = m-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            int row = maxelt(mat, n, mid);
            int left = (mid-1 >= 0) ? mat[row][mid-1] : -1;
            int right = (mid+1 < m) ? mat[row][mid+1] : -1;
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row,mid};
            }
            else if(mat[row][mid] < left){
                e = mid-1;
            }
            else{
                s = mid+1;
            }

        }
        return {-1,-1};
    }
};