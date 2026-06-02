class Solution {
public:
    int dp(vector<int>& coins, int amount, map<int, int>& mp){
        if (amount < 0) return 1e9;
        if (amount == 0) return 0;
        if (mp.find(amount) != mp.end()) return mp[amount];
        int minCoins = 1e9;
        for (auto c : coins){
            minCoins = min(minCoins, 1 + dp(coins, amount - c, mp));
        }
        return mp[amount] = minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        map<int, int> mp;
        int sol = dp(coins, amount, mp);
        if (sol == 1e9) return -1;
        return sol;
    }
};
