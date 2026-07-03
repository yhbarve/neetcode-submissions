class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        int mid;
        while (low <= high){
            mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) low++;
            else high--;
        }
        return -1;
    }
};
