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
    Node* clone(Node* node, map<Node*, Node*>&mp){
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        for (auto n : node->neighbors){
            if (mp.find(n) == mp.end()){
                Node* newNeighbor = clone(n, mp);
                newNode->neighbors.push_back(newNeighbor);
            } else {
                newNode->neighbors.push_back(mp[n]);
            }
        }
        return newNode;
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        map<Node*, Node*> mp;
        return clone(node, mp);
    }
};
