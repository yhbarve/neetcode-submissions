class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;

        for(auto s : strs){
            string sCopy = s;
            sort(s.begin(), s.end());
            mp[s].push_back(sCopy);
        }

        vector<vector<string>> sol;
        for (auto [i, j] : mp){
            sol.push_back(j);
        }

        return sol;
    }
};
