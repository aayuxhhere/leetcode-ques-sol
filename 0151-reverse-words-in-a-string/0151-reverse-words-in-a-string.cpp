class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string ans = "";
        for(int i=0; i<s.size(); i++){
            string word = "";
            while(i < s.length() && s[i] == ' '){
                i++;
            }
            while(i < s.length() && s[i] != ' '){
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if(word.empty()) continue;
            if(ans.length() != 0){
                ans += " " + word;
            }
            else{
                ans += word;
            }
            
        }
        return ans;
    }
};