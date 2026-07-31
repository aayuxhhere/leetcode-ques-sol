class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        if(n==1 || n==0){
            return n;
        }
        while(j<n){
            if(nums[i] == nums[j]){
                j++;
            }
            else{
                swap(nums[++i], nums[j++]);
            }
        }
        return i+1;
    }
};