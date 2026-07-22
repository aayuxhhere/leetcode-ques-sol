class Solution {
public:
    int totalhrs(vector<int>& piles, int speed, int h){
        int hrs = 0;

        for(int i = 0; i < piles.size(); i++){
            hrs += (piles[i] + speed - 1) / speed;

            if(hrs > h){
                return INT_MAX;
            }
        }

        return hrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxval = *max_element(piles.begin(), piles.end());

        int s = 1, e = maxval;
        int ans = maxval;

        while(s <= e){
            int mid = s + (e - s) / 2;

            int hrs = totalhrs(piles, mid, h);

            if(hrs <= h){      // valid speed
                ans = mid;
                e = mid - 1;   // try smaller speed
            }
            else{
                s = mid + 1;   // need faster speed
            }
        }

        return ans;
    }
};