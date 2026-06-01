class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int maxVolume = 0;
        while (i < j){
            maxVolume = max(maxVolume, min(heights[i], heights[j]) * (j - i));
            if (heights[i] <= heights[j]) i++;
            else j--;
        }
        return maxVolume;
    }
};
