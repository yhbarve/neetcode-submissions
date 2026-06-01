class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for (auto s : strs){
            vector<int> freq(26, 0);
            for (auto c : s){
                freq[c-'a']++;
            }
            mp[freq].push_back(s);
        }

        vector<vector<string>> sol;
        for (auto [x, y] : mp){
            sol.push_back(y);
        }

        return sol;
    }
};
