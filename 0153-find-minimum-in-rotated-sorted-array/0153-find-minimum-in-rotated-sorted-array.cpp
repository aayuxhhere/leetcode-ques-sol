class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        int mini = INT_MAX;
        while(s<=e){
            int mid = s + (e-s)/2;
            mini = min(mini, nums[mid]);

            //left part sorted
            if(nums[mid]<=nums[e]){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return mini;
    }
};