class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
            3, 4, 5, 6, 1, 2 | Target = 4
            #1 low = 0, high = 5, mid = 2 | 3, 5, 2 | 
        */

        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low <= high){
            mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[low]){
                // we're in the left sub-portion
                if (target < nums[low]){
                    // target is in the right sub-portion
                    low = mid + 1;
                    continue;
                }
                // target is in the left sub-portion
                if (target < nums[mid]) high = mid - 1;
                else low = mid + 1;
            } else {
                // we're in the right sub-portion
                if (target >= nums[low]){
                    // target is in the left-sub portion
                    high = mid - 1;
                    continue;
                }
                // target is in the right sub-portion
                if (target > nums[mid]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
};
