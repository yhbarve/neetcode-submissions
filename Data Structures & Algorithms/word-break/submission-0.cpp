class Solution {
public:
    bool backtrack(string s, vector<string>& wordDict, int i, map<int, bool>& mp){
        cout << i << "." << endl;
        if (i >= s.size()) return true; // we've matched all the previous chars
        if (mp.find(i) != mp.end()) return mp[i];
        bool sol = false;
        for (auto w : wordDict){
            if (i + w.size() > s.size()) continue;
            cout << s.substr(i, w.size()) << ", " << w << endl;
            if (s.substr(i, w.size()) == w){
                sol = sol || backtrack(s, wordDict, i + w.size(), mp);
                if (sol) cout << "Sol is true" << endl;
                else cout << "Sol is false" << endl;
            }
        }
        return mp[i] = sol;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        /*
            - t = 0 | ["neetcode"]
            - t = 1 | ["n", "eetcode"]
            - t = 2 | ["n", "e", "etcode"], ["ne", "etcode"]
            - t = 3 | ["n", "e", "e", "tcode"], ["n", "ee", "tcode"], ["nee", "tcode"]
        */
        map<int, bool> mp;
        return backtrack(s, wordDict, 0, mp);
    }
};
