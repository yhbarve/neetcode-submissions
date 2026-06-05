class Solution {
public:
    bool dfs(map<int, vector<int>>& mp, int curr, vector<bool> dependent){
        if (mp.find(curr) == mp.end()) return true; // no prereqs
        bool possible = true;
        for (auto i : mp[curr]){
            if (dependent[i]) return false;
            dependent[curr] = true;
            possible = possible && dfs(mp, i, dependent);
            if (!possible) return false;
        }
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            0 -> 1
            1 DONE
        */

        map<int, vector<int>> mp;
        for (auto i : prerequisites){
            mp[i[0]].push_back(i[1]);
        }

        vector<bool> dependent(numCourses, false);

        bool sol;
        for (int i = 0; i < numCourses; i++){
            sol = dfs(mp, i, dependent);
            if (!sol) return false;
        }
        return true;
    }
};
