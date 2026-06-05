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
    Node* dfs(Node* node, map<Node*, Node*>& mp){
        if (mp.find(node) != mp.end()) return mp[node];
        Node* copy = new Node(node->val);
        mp[node] = copy;
        for (auto i : node->neighbors){
            Node *neighborCopy = dfs(i, mp);
            copy->neighbors.push_back(neighborCopy);
        }
        return copy;
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};
