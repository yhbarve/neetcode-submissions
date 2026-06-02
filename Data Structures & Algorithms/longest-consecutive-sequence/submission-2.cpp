class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        for (auto n : nums){
            mp[n]++;
        }

        int maxLen = 0;
        for (auto [x, y] : mp){
            if (mp.find(x - 1) != mp.end()) continue;
            else{
                int len = 1;
                int num = x+1;
                while (mp.find(num) != mp.end()){
                    num++;
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};
