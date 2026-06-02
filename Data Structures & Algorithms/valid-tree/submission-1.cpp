class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> mp;
        for (auto e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        queue<pair<int, int>> q;
        q.push({0, -1});
        visited[0] = true;
        while (!q.empty()){
            int node = q.front().first;
            int src = q.front().second;
            cout << node << endl;
            q.pop();
            for (auto i : mp[node]){
                if (i == src){
                    cout << "Hahahaha" << endl;
                    continue;
                }
                if (visited[i]){
                    cout << i << endl;
                    cout << "Woooo" << endl;
                    return false;
                }
                q.push({i, node});
                visited[i] = true;
            }
        }
        for (auto i : visited){
            if (!i) return false;
        }
        return true;
    }
};
