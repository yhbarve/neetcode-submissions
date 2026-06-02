class Solution {
public:
    bool isValid(vector<int>& freqS, vector<int>& freqT){
        for (int i = 0; i < freqS.size(); i++){
            if (freqS[i] < freqT[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> freqT(52, 0);
        for (auto c : t){
            if (c >= 'a' && c <= 'z') freqT[c-'a'+26]++;
            else freqT[c-'A']++;
        }

        vector<int>freqS(52, 0);

        int i = 0;
        int j = 0;
        int minLen = INT_MAX;
        string minString = "";
        while (j < s.size()){
            if (s[j] >= 'a' && s[j] <= 'z') freqS[s[j]-'a'+26]++;
            else freqS[s[j]-'A']++;
            j++;

            while (i <= j && isValid(freqS, freqT)){
                if (s[i] >= 'a' && s[i] <= 'z') freqS[s[i]-'a'+26]--;
                else freqS[s[i]-'A']--;
                if (j - i < minLen){
                    minString = s.substr(i, j-i);
                    minLen = j - i;
                }
                i++;
            }

        }
        return minString;
    }
};
