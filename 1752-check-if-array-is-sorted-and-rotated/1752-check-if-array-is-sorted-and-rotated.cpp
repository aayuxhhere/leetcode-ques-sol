class Solution {
public:
    bool check(vector<int>& nums) {
        int pivot = -1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                if(pivot != -1){
                    return false;
                }
                pivot = i;
            }
        }
        if(pivot == -1) return true;

        if(nums[nums.size()-1] <= nums[0]){
            return true;
        }
        return false;
    }
};