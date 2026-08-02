class Solution {
public:
    //using depth
    string removeOuterParentheses(string s) {
        int depth = 0;
        string ans;
        for(int i = 0; i<s.length(); i++){
            if(s[i]== '(' && (depth++) > 0){
                ans += '(';
            }
            if(s[i]== ')' && (depth--) > 1){
                ans += ')';
            }
        }
        return ans;
    }
};