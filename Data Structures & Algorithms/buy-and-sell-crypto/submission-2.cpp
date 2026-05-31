class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] - prices[buy] < 0) buy = i;
            else{
                maxProfit = max(maxProfit, prices[i] - prices[buy]);
            }
        }
        return maxProfit;
    }
};
