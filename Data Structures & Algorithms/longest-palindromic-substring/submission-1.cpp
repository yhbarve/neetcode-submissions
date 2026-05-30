class Solution {
public:
    string longestPalindrome(string s) {
        // start at each index & move to the left & right till the chars are same
        // need to handle even and odd length palidromes

        if (s.size() == 1) return s;

        // odd length
        int maxPalindrome = 0;
        string maxPalindromeString = "";
        for (int i = 0; i < s.size(); i++){
            int x = i-1;
            int y = i+1;
            int size = 1;
            while (x >= 0 && y < s.size()){
                if (s[x] == s[y]){
                    size += 2;
                    if (size > maxPalindrome){
                        maxPalindromeString = s.substr(x, size);
                        maxPalindrome = size;
                    }
                    x--;
                    y++;
                } else {
                    break;
                }
            }
        }

        // even length
        for (int i = 0; i < s.size() - 1; i++){
            int x = i;
            int y = i+1;
            int size = 0;
            while (x >= 0 && y < s.size()){
                if (s[x] == s[y]){
                    size += 2;
                    if (size > maxPalindrome){
                        maxPalindromeString = s.substr(x, size);
                        maxPalindrome = size;
                    }
                    x--;
                    y++;
                } else {
                    break;
                }
            }
        }
        if (maxPalindromeString == ""){
            maxPalindromeString += s[0];
        }
        return maxPalindromeString;
    }
};
