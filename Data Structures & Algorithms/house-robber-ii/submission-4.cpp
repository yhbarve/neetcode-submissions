class Solution {
public:
    int rob(vector<int>& nums) {
        int i = nums.size();
        // dp[i] = max money that can be robbed from the first i houses
        // if i == 1, it's just one house -> so rob money from it
        // if i == 2, rob max money from first or second house
        // if i == 3, either rob house 2 or rob houses 1 & 3

        // Because we cannot rob both the first & last houses,
        // we will consider all houses except the first,
        // and then all houses except the last.
        // And we will pick the maximum value from these 2 cases.

        if (i == 1) return nums[0];
        if (i == 2) return max(nums[0], nums[1]);
        if (i == 3) return max (nums[1], max(nums[0], nums[2]));

        // All houses except last
        int x1 = nums[0];
        int x2 = max(nums[0], nums[1]);
        int x3;

        for (int i = 2; i < nums.size() - 1; i++){
            x3 = max(x2, x1 + nums[i]);
            x1 = x2;
            x2 = x3;
        }

        int sol = x2;
        cout << sol << endl;

        // All houses except first
        x1 = nums[1];
        x2 = max(nums[1], nums[2]);

        for (int i = 3; i < nums.size(); i++){
            x3 = max(x2, x1 + nums[i]);
            x1 = x2;
            x2 = x3;
        }
        cout << x2 << endl;
        cout << endl;
        sol = max(sol, x2);

        return sol;
    }
};
