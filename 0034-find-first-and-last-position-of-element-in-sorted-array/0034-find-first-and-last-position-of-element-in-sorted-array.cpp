class Solution {
public:
    int lowerbound(vector<int>& nums, int target){
        int start = 0, end = nums.size()-1;
        int ans = nums.size();
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid] >= target){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
    int upperbound(vector<int>& nums, int target){
        int start = 0, end = nums.size()-1;
        int ans = nums.size();
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid] > target){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerbound(nums,target);
        if(lb == nums.size() || nums[lb]!=target){
            return {-1,-1};
        }
        return {lb, upperbound(nums,target)-1};
    }
};