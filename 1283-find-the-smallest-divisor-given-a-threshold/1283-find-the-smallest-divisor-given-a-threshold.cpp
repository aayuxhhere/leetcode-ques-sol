class Solution {
public:
    bool ispossible(vector<int>& nums, int threshold, int key){
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += (nums[i] + key - 1)/key;
            if(sum > threshold){
                return false;
            }
        }
        return true;

    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxval = *max_element(nums.begin(), nums.end());
        if(nums.size()>=threshold){
            return maxval;
        }
        int s = 1, e = maxval, ans = maxval;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(ispossible(nums,threshold,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};