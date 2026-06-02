class Solution {
public:
    int rob(vector<int>& nums) {
        int x1 = nums[0];
        if (nums.size() == 1) return x1;
        int x2 = max(nums[0], nums[1]);
        if (nums.size() == 2) return x2;
        int x3;
        for (int i = 2; i < nums.size(); i++){
            x3 = max(x1 + nums[i], x2);
            // cout << i << endl << ": " << x1 << ", " << x2 << ", " << x3 << endl;
            x1 = x2;
            x2 = x3;
        }
        return x2;
    }
};
