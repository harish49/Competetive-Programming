class Trie {
private:
public:
    Trie*child[26] = {NULL};
    bool endword = false;
    
    void insert(string word) {
        Trie*root = this;
        for(int i = 0 ; i < word.size() ; i++){
            int id = word[i]-'a';
            if(!root->child[id]){
                root->child[id] = new Trie();
            }
            root = root->child[id];
        }
        root->endword = true;
    }
    bool search(string word) {
        Trie*root = this;
        for(int i = 0 ; i < word.size() ; i++){
            int id = word[i]-'a';
            if(!root->child[id]){
                return false;
            }
            root = root->child[id];
        }
        return (root!=NULL) && root->endword==true;
    }
    
    bool startsWith(string prefix) {
        Trie*root = this;
        for(int i = 0 ; i < prefix.size() ; i++){
            int id = prefix[i]-'a';
            if(!root->child[id]){
                return false;
            }
            root = root->child[id];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
