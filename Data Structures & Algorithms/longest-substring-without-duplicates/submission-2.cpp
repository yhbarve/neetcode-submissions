class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        map<char, int> mp;
        int maxLen = 0;
        while (i <= j && j < s.size()){
            // cout << i << ", " << j << endl;
            while (j < s.size() && mp.find(s[j]) == mp.end()){
                mp[s[j]]++;
                j++;
                // cout << i << ",, " << j << endl;
                maxLen = max(maxLen, j - i);
            }
            while (i <= j && mp.find(s[j]) != mp.end()){
                mp[s[i]]--;
                if (mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
        }
        return maxLen;
    }
};
