class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> mp;
        for (auto s : strs){
            map<char, int> strMap;
            for (auto c : s){
                strMap[c]++;
            }
            mp[strMap].push_back(s);
        }

        vector<vector<string>> sol;
        for (auto [x, y] : mp){
            sol.push_back(y);
        }

        return sol;
    }
};
