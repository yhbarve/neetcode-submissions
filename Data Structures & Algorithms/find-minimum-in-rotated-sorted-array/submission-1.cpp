class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size() - 1;
        int minLow = INT_MAX;
        if (nums[low] <= nums[high]) return nums[low];

        while (low <= high){
            int mid = (low + high) / 2;
            minLow = min(minLow, nums[mid]);
            if (nums[mid] >= nums[low] && nums[mid] > nums[high]) low = mid + 1;
            else high = mid - 1;
        }
        return minLow;
    }
};
