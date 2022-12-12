class TrieNode {

public:
    
    std::vector<TrieNode*> child;
    bool isEnd;
    
    TrieNode() {
        
        child.resize(26, nullptr);
        isEnd = false;
    }
};

class Trie {
    
public:
    
    TrieNode* root;
    
    Trie() {
        
        root = new TrieNode();
    }
    
    bool nodeIsEmpty(TrieNode* node) {
        
        bool isEmpty = true;
        
        for (auto c: node -> child) {
            
            isEmpty &= (c == nullptr);
        }
        
        return isEmpty;
    }
    
    void insert(std::string word) {
        
        TrieNode* curNode = root;
        
        for (auto c: word) {
            
            TrieNode* childNode = curNode -> child[c - 'a'];
            
            if (childNode == nullptr) {
                
                childNode = new TrieNode();
                curNode -> child[c - 'a'] = childNode;
            }
            
            curNode = childNode;
        }
        
        curNode -> isEnd = true;
    }
    
    bool find(std::string word) {
        
        TrieNode* curNode = root;
        
        for (auto c: word) {
            
            TrieNode* childNode = curNode -> child[c - 'a'];
            
            if (childNode == nullptr) return false;
            
            curNode = childNode;
        }
        
        return curNode -> isEnd;
    }
    
    void erase(std::string word) {
        
        _erase(root, 0, word);
    }
    
    bool _erase(TrieNode* curNode, ll pos, std::string& word) {
        
        if (pos == len(word)) {
            
            if (!curNode -> isEnd) return false;
            
            curNode -> isEnd = false;
            
            return nodeIsEmpty(curNode);
        }
        
        char ch = word[pos];
        TrieNode* childNode = curNode -> child[ch - 'a'];
        
        if (childNode == nullptr) return false;
        
        bool shouldDelete = _erase(childNode, pos + 1, word);
        
        if (shouldDelete) {
            
            curNode -> child[ch - 'a'] = nullptr;
            
            return nodeIsEmpty(curNode);
        }
        
        return false;
    }
};
