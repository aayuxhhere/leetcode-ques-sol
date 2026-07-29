class Solution {
public:
    int daysreq(vector<int>& weights,int capacity){
        int d = 1;
        int sum = 0;
        for(int i=0; i<weights.size(); i++){
            if(sum + weights[i] > capacity){
            d++;
            sum = weights[i];
            }
            else{
                sum += weights[i];
            }
        }
        return d;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int capacity = *max_element(weights.begin(), weights.end());
        long long int sum = 0;
        for(int i=0; i<weights.size(); i++){
            sum+=weights[i];
        }
        int s = capacity, e = sum;
        while(s<=e){
            int mid = s + (e-s)/2;
            int d = daysreq(weights, mid);
            if(d <= days){
                capacity = mid;
                e = mid-1; 
            }
            else{
                s = mid+1;
            }
        }
        return capacity;
    }
};