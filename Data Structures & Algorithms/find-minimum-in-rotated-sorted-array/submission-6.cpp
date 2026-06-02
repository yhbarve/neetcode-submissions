class Solution {
public:
    int findMin(vector<int> &nums) {
        // 3, 4, 5, 6, 1, 2 | low = 0, high = 5, mid = 2
        // low = mid + 1 | low = 3, high = 5, mid = 4
        // high = mid - 1 | low = 3, high = 3, mid = 3
        // low = mid + 1 | low = 4, high = 3, STOP

        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int minNum = INT_MAX;
        while (low <= high){
            if (nums[low] <= nums[high]){
                minNum = min(minNum, nums[low]);
                return minNum;
            }
            mid = (low + high) / 2;
            cout << nums[low] << ", " << nums[mid] << ", " << nums[high] << endl;
            if (nums[mid] >= nums[low]){
                // left sorted portion
                low = mid + 1;
            } else {
                // right sorted portion
                minNum = min(minNum, nums[mid]);
                high = mid - 1;
            }
        }
        return minNum;
    }
};
