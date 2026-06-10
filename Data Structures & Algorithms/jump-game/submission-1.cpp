class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--){
            if (nums[i] >= (pos - i)){
                pos = i;
            }
        }
        if (pos == 0) return true;
        return false;
    }
};
