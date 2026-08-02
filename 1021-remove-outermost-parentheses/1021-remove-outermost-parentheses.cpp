class Solution {
public:
    //using stack
    string removeOuterParentheses(string s) {
        stack<char> st;
        int start = 0;
        string ans;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                st.push('(');
            }
            else{
                st.pop();
            }
            if(st.empty()){
                for(int j = start+1; j<i; j++){
                    ans += s[j];
                }
                start = i+1;
            }
        }
        return ans;
    }
};