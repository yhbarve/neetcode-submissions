class Solution {
public:
    bool valid(vector<int>& freq, int k){
        int mostFreq = 0;
        int size = 0;
        for (auto i : freq){
            mostFreq = max(mostFreq, i);
            size += i;
        }
        return (size - mostFreq <= k);
    }

    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int i = 0;
        int j = 0;
        int maxLen = 0;
        while (j < s.size()){
            freq[s[j]-'A']++;
            j++;
            while (i <= j && !valid(freq, k)){
                freq[s[i]-'A']--;
                i++;
            }
            maxLen = max(maxLen, j - i);
        }
        return maxLen;
    }
};
