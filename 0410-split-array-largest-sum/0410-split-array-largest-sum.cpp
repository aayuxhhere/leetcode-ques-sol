class Solution {
public:
    int countit(vector<int>& nums, int key){
        long long int out = 0;
        int cnt = 1;
        for(int i=0; i<nums.size(); i++){
            if(out + nums[i] <= key){
                out += nums[i];
            }
            else{
                cnt++;
                out = nums[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(),0);
        while(s<=e){
            int mid = s + (e-s)/2;
            if(countit(nums,mid) > k){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return s;
    }
};