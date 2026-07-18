class Solution {
public:
    //int cnt = 0;
    void merge(vector<int>& nums,int s,int mid, int e){

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
    int cntpairs(vector<int>& nums,int s,int mid, int e){
        int j = mid+1;
        int cnt = 0;
        for(int i = s; i<=mid; i++){
            while(j <= e && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += j - (mid + 1);
        }
        return cnt;
    }

    int mergesort(vector<int>& nums,int s, int e){
        int cnt = 0;
        if(s>=e){
            return cnt;
        }
        int mid = s + (e-s)/2;
        cnt += mergesort(nums,s,mid);
        cnt += mergesort(nums,mid+1,e);
        cnt += cntpairs(nums,s,mid,e);
        merge(nums,s,mid,e);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size()-1);
        //return cnt;
    }
};