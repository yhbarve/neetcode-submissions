class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        map<int, set<int>> mp;
        for (auto n : nums){
            mp[0].insert(n);
        }

        for (auto n : nums){
            freq[n]++;
            mp[freq[n]-1].erase(n);
            mp[freq[n]].insert(n);
        }

        int ct = k;
        vector<int> sol;
        for (auto it = mp.rbegin(); it != mp.rend(); it++){
            for (auto n : it->second){
                sol.push_back(n);
                ct--;
                if (ct == 0) return sol;
            }
        }
        return {-1};
    }
};
