class Solution {
public:
    bool ispossible(vector<int>& bloomDay, int m, int k, int day){
        int count = 0, bouquets = 0;
        for(int i : bloomDay){
            if(i <= day){
                count++;
                if(count >= k){
                    bouquets++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }
        if(bouquets >= m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m*k){
            return -1;
        }
        int maxval = *max_element(bloomDay.begin(), bloomDay.end());
        int s = 0, e = maxval;
        int ans = maxval;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(ispossible(bloomDay, m, k, mid)){
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