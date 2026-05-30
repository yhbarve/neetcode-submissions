class Solution {
public:
    int getMaxFreq(vector<int> freq){
        int maxFreq = 0;
        for (auto i : freq){
            maxFreq = max(maxFreq, i);
        }
        return maxFreq;
    }
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int i = 0;
        int j = 0;
        int maxLen = 0;
        while (i <= j && j < s.size()){
            freq[s[j]-'A']++;
            int maxFreq = getMaxFreq(freq);
            while ((j - i + 1) - maxFreq > k){
                freq[s[i]-'A']--;
                i++;
            }
            for (int x = i; x <= j; x++){
                cout << s[x] << " ";
            }
            cout << endl;
            maxLen = max(maxLen, (j - i + 1));
            j++;
        }
        return maxLen;
    }
};
