class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int> freq;
        for(char ch : s){
            freq[ch]++;
        }
        vector<string> bucket(s.size()+1);
        for(auto x : freq){
            bucket[x.second] += x.first;
        }
        string ans;
        for(int i = s.size(); i>=1; i--){
            for(char c : bucket[i])
                ans.append(i, c);
        }
        return ans;
    }
};