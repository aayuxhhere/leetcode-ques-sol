class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //2 1 5 4 3 0 0 find pivot -- step 1
        //2 3 5 4 1 0 0 swap with just greater number
        //2 3 0 0 1 4 5

        //5 4 3 2 1
        //1 2 3 4 5 
        int index = -1;
        for(int i = nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = nums.size()-1; i>=index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1, nums.end());
        return;
    }
};