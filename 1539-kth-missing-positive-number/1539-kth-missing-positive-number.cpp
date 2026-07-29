class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int j = 0;
        int cnt = 0;
        for(int i=0; i<arr.size()+k; i++){
            if(j < arr.size() && i+1 == arr[j]){
                j++;
            }
            else{
                cnt++;
            }
            if(cnt == k){
                return i+1;
            }
        }
        return -1;
    }
};