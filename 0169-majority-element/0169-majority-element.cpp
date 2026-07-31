class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elt = -1;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(count == 0){
                elt = nums[i];
                count = 1;
            }
            else if(elt == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==elt){
                cnt++;
            }
        }
        if(cnt>nums.size()/2){
            return elt;
        }
        else{
            return -1;
        }
    }
};