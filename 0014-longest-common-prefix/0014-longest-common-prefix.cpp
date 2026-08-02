class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int j = 0;

        while (true) {
            if (j >= strs[0].size()) break;

            bool flag = true;
            char ch = strs[0][j];

            for (int i = 1; i < strs.size(); i++) {
                if (j >= strs[i].size() || ch != strs[i][j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ans += ch;
                j++;
            } else {
                break;
            }
        }

        return ans;
    }
};