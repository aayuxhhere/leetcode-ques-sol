class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        vector<int> temp1(26, 0);
        for(int i=0 ;i<s.length(); i++){
            temp1[(s[i] - 'a')]++;
            temp1[(t[i] - 'a')]--;
        }
        for(int i : temp1){
            if(i != 0){
                return false;
            }
        }
        return true;

    }
};