struct Node {
    Node *links[26];
    bool end = false;
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
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
        for (auto w : word){
            if (!node->containsKey(w)){
                Node *newNode = new Node();
                node->links[w - 'a'] = newNode;
            }
            node = node->links[w-'a'];
        }
        node->end = true;
    }
    
    bool search(string word) {
        Node *node = root;
        for (auto w : word){
            if (!node->containsKey(w)) return false;
            node = node->links[w-'a'];
        }
        return (node->end == true);
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for (auto w : prefix){
            if (!node->containsKey(w)) return false;
            node = node->links[w-'a'];
        }
        return true;
    }
};
