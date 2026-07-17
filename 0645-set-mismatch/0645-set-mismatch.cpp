class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> hashing(nums.size()+1, 0);
        for(int i=0; i<nums.size(); i++){
            hashing[nums[i]]++;
        }
        int missing = -1;
        int repeating = -1;
        for(int i=1; i<hashing.size(); i++){
            if(hashing[i]==0){
                missing = i;
            }
            if(hashing[i]==2){
                repeating = i;
            }
        }
        return {repeating, missing};
    }
};