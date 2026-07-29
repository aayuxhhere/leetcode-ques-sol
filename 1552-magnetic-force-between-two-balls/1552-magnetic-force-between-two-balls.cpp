class Solution {
public:
    bool ispossible(vector<int>& position, int m, int dist){
        int cnt = 1;
        int lastpos = position[0];
        for(int i=1; i<position.size(); i++){
            if(position[i]-lastpos >= dist){
                cnt++;
                lastpos = position[i];
                if(cnt >= m){
                    return true;
                }
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int ans = 0;
        int s = 1, e = position.back() - position.front();
        while(s<=e){
            int mid = s + (e-s)/2;
            if(ispossible(position, m, mid)){
                s = mid+1;
                ans = mid;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};