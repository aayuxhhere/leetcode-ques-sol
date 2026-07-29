class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> dummy;
        for(int i=0; i<arr.size()+k; i++){
            dummy.push_back(i+1);
        }
        int j = 0;
        int cnt = 0;
        for(int i=0; i<dummy.size(); i++){
            if(j < arr.size() && dummy[i] == arr[j]){
                j++;
            }
            else{
                cnt++;
            }
            if(cnt == k){
                return dummy[i];
            }
        }
        return -1;
    }
};