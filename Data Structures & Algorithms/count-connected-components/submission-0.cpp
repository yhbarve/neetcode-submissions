class Solution {
public:
    void dfs(map<int, vector<int>>& adjList, int i, vector<bool>& visited){
        if (visited[i]) return;
        visited[i] = true;
        for (auto j : adjList[i]){
            dfs(adjList, j, visited);
        }
        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> adjList;
        vector<bool> visited(n, false);
        for (auto i : edges){
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }

        int sol = 0;
        for (int i = 0; i < n; i++){
            if (!visited[i]){
                sol++;
                dfs(adjList, i, visited);
            }
        }

        return sol;
    }
};
