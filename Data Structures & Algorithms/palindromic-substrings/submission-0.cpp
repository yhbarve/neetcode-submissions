class Solution {
public:
    int countSubstrings(string s) {
        // same as longest palindromic substring
        // except this time we maintain a counter

        // define vars
        int counter = 0;
        if (s.size() == 1) return 1;

        // even case
        for (int i = 0; i < s.size() - 1; i++){
            int x = i;
            int y = i+1;
            while (x >= 0 && y < s.size()){
                if (s[x] == s[y]){
                    counter++;
                    x--;
                    y++;
                } else {
                    break;
                }
            }
        }

        // odd case
        for (int i = 0; i < s.size(); i++){
            counter++;
            int x = i-1;
            int y = i+1;
            while (x >= 0 && y < s.size()){
                if (s[x] == s[y]){
                    counter++;
                    x--;
                    y++;
                } else {
                    break;
                }
            }
        }

        return counter;
    }
};
