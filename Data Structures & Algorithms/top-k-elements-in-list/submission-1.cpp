class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto i : nums){
            mp[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto [x, y] : mp){
            pq.push({y, x});
            while (pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> sol;
        while (!pq.empty()){
            sol.push_back(pq.top().second);
            pq.pop();
        }

        return sol;
    }
};
