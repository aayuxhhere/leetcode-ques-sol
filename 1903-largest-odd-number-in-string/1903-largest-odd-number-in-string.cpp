class Solution {
public:
    string largestOddNumber(string num) {
        string ans;
        int i = 0;
        int j = num.size()-1;
        while(j >= 0){
            if(num[j] % 2 == 1){
                while(i <= j){
                    ans += num[i++];
                }
                break;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};