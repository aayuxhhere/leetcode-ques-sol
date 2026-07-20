class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[s] == nums[mid] && nums[mid] == nums[e]){
                s++;
                e--;
                continue;
            }
            //left part is sorted
            if(nums[s] <= nums[mid]){
                if(nums[s] <= target && nums[mid]>= target){
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
            //right part is sorted
            else{
                if(nums[e] >= target && nums[mid]<= target){
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
        }
        return false;
    }
};