class Solution {
public:
    bool isPalindrome(string s) {
        string sFormatted = "";
        for (auto c : s){
            if (c >= 'a' && c <= 'z'){
                sFormatted += c;
            } else if (c >= 'A' && c <= 'Z'){
                sFormatted += c + ('a' - 'A');
            } else if (c >= '0' && c <= '9'){
                sFormatted += c;
            }
        }

        int i = 0;
        int j = sFormatted.size() - 1;
        while (i <= j){
            if (sFormatted[i] != sFormatted[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
