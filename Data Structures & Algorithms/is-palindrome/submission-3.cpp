class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        int i = 0;
        int j = s.size() - 1;
        while (i <= j){
            while (i < s.size() && !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))){
                i++;
            }
            while (j >= 0 && !((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9'))){
                j--;
            }
            if (s[i] >= '0' && s[i] <= '9'){
                if (s[i] != s[j]) return false;
            } else {
                if (tolower(s[i]) != tolower(s[j])) return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
