/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* graph, Node* prev, map<int, Node*>& mp){
        Node* copy = new Node(graph->val);
        cout << "Created " << copy->val << endl;
        mp[copy->val] = copy;
        cout << graph->neighbors.size() << endl;
        for (auto i : graph->neighbors){
            cout << i->val << endl;
            if (prev != nullptr && i->val == prev->val) continue;
            // cout << "Exploring " << i->val << endl;
            if (mp.find(i->val) != mp.end()){
                copy->neighbors.push_back(mp[i->val]);
                continue;
            }
            Node* neighborCopy = dfs(i, graph, mp);
            copy->neighbors.push_back(neighborCopy);
            neighborCopy->neighbors.push_back(copy);
        }
        return copy;
    }

    Node* cloneGraph(Node* node) {
        /*
            Dry Run:
            - Go to Node 1
            - Create Node 1
            - Explore it's neighbours
                - Go to Node 2
                - Create Node 2
                - Explore it's neighbours
                    - Go to Node 3
                    - Create Node 3
                    - No new neighbours
                - Add Node 3 as neighbour (undirected chain)
            - Add Node 2 as neighbour (undirected)

            Dry Run if 3->1 was a link:
            - Go to Node 1
            - Create Node 1
            - Explore neighbors
                - Go to Node 2
                - Create Node 2
                - Explore it's neighbours
                    - Go to Node 3
                    - Explore it's neighbours
                    - Node 1 already exists, so we'll deal with it later
                - Add Node 3 as neighbour
            - Add Node 2 as neighbour
                - Go to Node 3
                - No new neighbours
            - Add Node 3 as neigbour
        */
        if (node == nullptr) return nullptr;
        map<int, Node*> mp;
        return dfs(node, nullptr, mp);
    }
};
