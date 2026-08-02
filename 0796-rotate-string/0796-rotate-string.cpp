class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s == goal) return true;

            char ch = goal[n - 1];
            for(int j = n - 1; j > 0; j--)
                goal[j] = goal[j - 1];
            goal[0] = ch;
        }
        return false;
    }
};