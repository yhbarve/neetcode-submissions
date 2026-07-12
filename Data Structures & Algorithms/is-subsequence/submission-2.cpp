class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        if (t.size() == 0) return false;
        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size()){
            if (s[i] == t[j]){
                i++;
            }
            if (i == s.size()) return true;
            j++;
        }
        return false;
    }
};