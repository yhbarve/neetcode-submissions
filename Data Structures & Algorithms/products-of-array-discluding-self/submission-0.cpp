class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
            ar0 = [1, 2, 4, 6]
            ar1 = [1, 1, 2, 8]
            ar2 = [48, 24, 6, 1]
            sol - [48, 24, 12, 8]
        */

        vector<int> auxArray(nums.size(), 1);
        int cumProd = 1;
        // left -> right
        for (int i = 0; i < nums.size(); i++){
            auxArray[i] *= cumProd;
            cumProd *= nums[i];
        }
        // right -> left
        cumProd = 1;
        for (int i = nums.size() - 1; i >= 0; i--){
            auxArray[i] *= cumProd;
            cumProd *= nums[i];
        }
        return auxArray;
    }
};
