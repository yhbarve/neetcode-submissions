class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxElement = -1;
        int n = arr.size();
        vector<int> sol(n, 0);
        for (int i = n-1; i >= 0; i--){
            sol[i] = maxElement;
            maxElement = max(maxElement, arr[i]);
        }
        return sol;
    }
};