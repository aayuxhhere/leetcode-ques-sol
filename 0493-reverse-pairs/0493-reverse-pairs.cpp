class Solution {
public:
    int cnt = 0;
    void merge(vector<int>& nums,int s,int mid, int e){

        int j = mid+1;
        for(int i = s; i<=mid; i++){
            while(j <= e && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += j - (mid + 1);
        }

        vector<int> temp;
        int left = s;
        int right = mid+1;
        while(left<=mid && right<=e){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }
        while(left<=mid){
            temp.push_back(nums[left++]);
        }
        while(right<=e){
            temp.push_back(nums[right++]);
        }
        for(int i=0; i<temp.size(); i++){
            nums[s+i] = temp[i];
        }
    }

    void mergesort(vector<int>& nums,int s, int e){
        if(s>=e){
            return;
        }
        int mid = s + (e-s)/2;
        mergesort(nums,s,mid);
        mergesort(nums,mid+1,e);
        merge(nums,s,mid,e);
    }

    int reversePairs(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        return cnt;
    }
};