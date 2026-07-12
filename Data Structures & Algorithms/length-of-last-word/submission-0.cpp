class Solution {
public:
    int lengthOfLastWord(string s) {
        int prevLen = 0;
        int len = 0;
        for (auto i : s){
            if (i == ' '){
                if (len != 0) prevLen = len;
                len = 0;
            }
            else len++;
        }
        if (len == 0) return prevLen;
        else return len;
    }
};