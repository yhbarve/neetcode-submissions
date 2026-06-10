class Node {
public:
    Node *chars[26];
    bool flag = false;
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *cur = root;
        for (auto i : word){
            if (cur->chars[i-'a'] == NULL){
                cur->chars[i-'a'] = new Node();
            }
            cur = cur->chars[i-'a'];
        }
        cur->flag = true;
    }
    
    bool searchHelp(string word, Node *cur, int index){
        if (index == word.size()) return cur->flag;

        if (word[index] == '.'){
            for (int i = 0; i < 26; i++){
                if (cur->chars[i] != NULL){
                    if (searchHelp(word, cur->chars[i], index+1)) return true;
                }
            }
            return false;
        }

        if (cur->chars[word[index]-'a'] != NULL){
            return searchHelp(word, cur->chars[word[index]-'a'], index + 1);
        }

        return false;
    }

    bool search(string word) {
        Node *cur = root;
        return searchHelp(word, cur, 0);
    }
};
