class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // map<int, int> indexMap;
        // for (int i = 0; i < nums.size(); i++){
        //     indexMap[nums[i]] = i;
        // }
        sort(nums.begin(), nums.end());
        for (auto n : nums){
            cout << n << " ";
        }
        cout << endl;
        set<vector<int>> solSet;

        for (int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k){
                cout << nums[i] << " ";
                cout << nums[j] << " ";
                cout << nums[k] << endl;
                if (nums[i] + nums[j] + nums[k] == 0){
                    solSet.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (nums[i] + nums[j] + nums[k] < 0){
                    j++;
                } else {
                    k--;
                }
                
            }
        }

        vector<vector<int>> sol(solSet.begin(), solSet.end());
        return sol;
    }
};
