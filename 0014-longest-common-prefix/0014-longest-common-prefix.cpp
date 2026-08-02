class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0){
            return "";
        }
        sort(strs.begin(), strs.end());
        int m = min(strs[0].size(), strs[n-1].size());
        string ans;
        for(int i = 0; i<m; i++){
            if(strs[0][i] == strs[n-1][i]){
                ans += strs[0][i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};