struct Node {
    Node *links[26];
    bool flag = false;
};

class PrefixTree {
private:
    Node *root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for (auto i : word){
            if (node->links[i - 'a'] == NULL){
                node->links[i - 'a'] = new Node();
            }
            node = node->links[i - 'a'];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node *node = root;
        for (auto i : word){
            if (node->links[i - 'a'] == NULL) return false;
            node = node->links[i - 'a'];
        }
        if (node->flag == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for (auto i : prefix){
            if (node->links[i - 'a'] == NULL) return false;
            node = node->links[i - 'a'];
        }
        return true;
    }
};
