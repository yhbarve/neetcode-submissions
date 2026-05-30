class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> sol(n+1, -1);
        sol[0] = 0;

        for (int i = 1; i <= n; i++){
            int num = i;
            int ct = 0;
            while (num != 0){
                if (sol[num] != -1){
                    ct += sol[num];
                    break;
                }
                if (num % 2 == 1) ct++;
                num /= 2;
            }
            sol[i] = ct;
        }

        return sol;
    }
};
