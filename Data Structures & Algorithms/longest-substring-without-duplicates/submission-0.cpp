class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int i = 0;
        int j = 0;
        int maxLen = 0;
        while (i <= j && j < s.size()){
            mp[s[j]]++;
            while (mp[s[j]] != 1){
                mp[s[i]]--;
                if (mp[s[i]] == 0) mp.erase(s[i]);
                i++;
                cout << "increment i to " << i << endl;
            }
            
            cout << i << ", " << j << endl;
            cout << s[i] << ", " << s[j] << endl;
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};
