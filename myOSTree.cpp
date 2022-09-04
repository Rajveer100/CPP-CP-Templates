enum colour {red, black};

struct Node {
    
    ll data, size;
    bool colour;
    
    Node* parent;
    Node* left;
    Node* right;
};

class RBTree {
    
    Node* root;
    Node* tNil;
    
    ll cnt;
    
    Node* findNode(Node* z) {
        
        Node* x = this -> root;
        
        while (x != tNil) {
            
            if (x -> data == z -> data) {
                
                return x;
            } else if (z -> data < x -> data) {
                
                x = x -> left;
            } else {
                
                x = x -> right;
            }
        }
        
        return tNil;
    }
    
    Node* findMin(Node *z) {
        
        while (z -> left != tNil) {
            
            z = z -> left;
        }
        
        return z;
    }
    
    void leftRotate(Node* x) {
        
        if (x -> right == tNil) {
            
            return;
        }
        
        Node* y = x -> right;
        x -> right = y -> left;
        
        if (y -> left != tNil) {
            
            y -> left -> parent = x;
        }
        
        y -> parent = x -> parent;
        
        if (x -> parent == tNil) {
            
            this -> root = y;
        } else if (x == x -> parent -> left) {
            
            x -> parent -> left = y;
        } else {
            
            x -> parent -> right = y;
        }
        
        y -> left = x;
        x -> parent = y;
        y -> size = x -> size;
        x -> size = x -> left -> size + x -> right -> size + 1;
    }
    
    void rightRotate(Node* y) {
        
        if (y -> left == tNil) {
            
            return;
        }
        
        Node* x = y -> left;
        y -> left = x -> right;
        
        if (x -> right != tNil) {
            
            x -> right -> parent = y;
        }
        
        x -> parent = y -> parent;
        
        if (y -> parent == tNil) {
            
            this -> root = x;
        } else if (y == y -> parent -> right) {
            
            y -> parent -> right = x;
        } else {
            
            y -> parent -> left = x;
        }
        
        x -> right = y;
        y -> parent = x;
        x -> size = y -> size;
        y -> size = y -> left -> size + y -> right -> size + 1;
    }
    
    void insertFixUp(Node* z) {
        
        while (z -> parent -> colour == red) {
            
            if (z -> parent == z -> parent -> parent -> left) {
                
                Node* y = z -> parent -> parent -> right;
                
                if (y -> colour == red) {
                    
                    z -> parent -> colour = black;
                    y -> colour = black;
                    
                    if (z -> parent -> parent != this -> root) {
                        
                        z -> parent -> parent -> colour = red;
                    }
                    
                    z = z -> parent -> parent;
                } else {
                    
                    if ( z== z -> parent -> right) {
                        
                        z = z -> parent;
                        leftRotate(z);
                    }
                    
                    z -> parent -> colour = black;
                    z -> parent -> parent -> colour = red;
                    rightRotate(z -> parent -> parent);
                }
            } else {
                
                Node* y = z -> parent -> parent -> left;
                
                if (y -> colour == red) {
                    
                    z -> parent -> colour = black;
                    y -> colour = black;
                    
                    if (z -> parent -> parent != this -> root) {
                        
                        z -> parent -> parent -> colour = red;
                    }
                    
                    z = z -> parent -> parent;
                } else {
                    
                    if (z == z -> parent -> left) {
                        
                        z = z -> parent;
                        rightRotate(z);
                    }
                    
                    z -> parent -> colour = black;
                    z -> parent -> parent -> colour = red;
                    leftRotate(z -> parent -> parent);
                }
            }
        }
    }
    
    void insertNode(Node* z) {
        
        if (this -> root == tNil) {
            
            z -> colour = black;
            this -> root = z;
            this -> root -> size = 1;
            return;
        }
        
        Node* y = tNil;
        Node* x = this -> root;
        
        while (x != tNil) {
            
            y = x;
            x -> size++;
            
            if (z -> data < x -> data) {
                
                x = x -> left;
            } else {
                
                x = x -> right;
            }
        }
        
        z -> parent = y;
        
        if ( z -> data < y -> data) {
            
            y -> left = z;
        } else {
            
            y -> right = z;
        }
        
        insertFixUp(z);
    }
    
    void transplant(Node* u, Node* v) {
        
        if (u -> parent == tNil) {
            
            this -> root = v;
        } else if (u == u -> parent -> left) {
            
            u -> parent -> left = v;
        } else {
            
            u -> parent -> right = v;
        }
        
        v -> parent = u -> parent;
    }
    
    void deleteFixUp(Node* x) {
        
        while (x != this -> root && x -> colour == black) {
            
            if (x == x -> parent -> left) {
                
                Node* w = x -> parent -> right;
                
                if (w -> colour == red) {
                    
                    w -> colour = black;
                    x -> parent -> colour = red;
                    leftRotate(x -> parent);
                    
                    w = x -> parent -> right;
                }
                
                if (w -> left -> colour == black && w -> right -> colour == black) {
                    
                    w -> colour = red;
                    x = x -> parent;
                } else {
                    
                    if (w -> right -> colour == black) {
                        
                        w -> left -> colour = black;
                        w -> colour = red;
                        rightRotate(w);
                        
                        w = x -> parent -> right;
                    }
                    
                    w -> colour = x -> parent -> colour;
                    x -> parent -> colour = red;
                    w -> right -> colour = black;
                    leftRotate(x -> parent);
                    x = this -> root;
                }
            } else {
                
                Node* w = x -> parent -> left;
                
                if (w -> colour == red) {
                    
                    w -> colour = black;
                    x -> parent -> colour = red;
                    rightRotate(x -> parent);
                    
                    w = x -> parent -> left;
                }
                
                if (w -> right -> colour == black && w -> left -> colour == black) {
                    
                    w -> colour = red;
                    x = x -> parent;
                } else {
                    
                    if (w -> left -> colour == black) {
                        
                        w -> right -> colour = black;
                        w -> colour = red;
                        leftRotate(w);
                        
                        w = x -> parent -> left;
                    }
                    
                    w -> colour = x -> parent -> colour;
                    x -> parent -> colour = red;
                    w -> left -> colour = black;
                    rightRotate(x -> parent);
                    x = this -> root;
                }
            }
        }
        
        x -> colour = black;
    }
    
    void deleteNode(Node* z) {
        
        Node* y = z;
        Node* x;
        bool originalColour = y -> colour;
        
        if (z -> left == tNil) {
            
            x = z -> right;
            transplant(z, z -> right);
        } else if (z -> right == tNil) {
            
            x = z -> left;
            transplant(z, z -> left);
        } else {
            
            y = findMin(z -> right);
            originalColour = y -> colour;
            
            x = y -> right;
            
            if (y -> parent == z) {
                
                x -> parent = y;
            } else {
                
                transplant(y, y -> right);
                y -> right = z -> right;
                y -> right -> parent = y;
                
                Node* s = x -> parent;
                
                while (s != tNil && s != y) {
                    
                    s -> size--;
                    s = s -> parent;
                }
            }
            
            transplant(z, y);
            
            y -> left = z -> left;
            y -> left -> parent = y;
            y -> colour = z -> colour;
            
            y -> size = y -> left -> size + y -> right -> size + 1;
        }
        
        if (originalColour == black) {
            
            deleteFixUp(x);
        }
    }
    
    void inOrderHelper(Node* node) {
        
        if (node == tNil) {
            
            return;
        }
        
        inOrderHelper(node -> left);
        
        std::cout << node -> data << " ";
        
        inOrderHelper(node -> right);
    }
    
public:
    
    RBTree() {
        
        tNil = new Node();
        tNil -> colour = black;
        tNil -> size = 0;
        
        tNil -> left = tNil;
        tNil -> right = tNil;
        tNil -> parent = tNil;
        
        this -> root = tNil;
        
        cnt = 0;
    }
    
    Node* getRoot() {
        
        return this -> root;
    }
    
    bool isNull(Node* node) {
        
        return node == tNil;
    }
    
    Node* find(ll key) {
        
        Node* z = new Node();
        
        z -> data = key;
        
        return findNode(z);
    }
    
    void insert(ll key) {
        
        Node* z = new Node();
        z -> data = key;
        z -> colour = red;
        z -> size = 1;
        
        z -> left = tNil;
        z -> right = tNil;
        z -> parent = tNil;
        
        insertNode(z);
        
        cnt++;
    }
    
    void erase(ll key) {
        
        Node* z = find(key);
        
        if (z == tNil) {
            
            return;
        }
        
        Node* s = z -> parent;
        
        while (s != tNil) {
            
            s -> size--;
            s = s -> parent;
        }
        
        deleteNode(z);
        
        cnt--;
    }
    
    ll lessThan(ll x) {
        
        Node* y = this -> root;
        
        ll z = 0;
        
        while (y != tNil) {
            
            if (x > y -> data) {
                
                z += y -> left -> size + 1;
                y=y->right;
            } else {
                
                y = y -> left;
            }
        }
        
        return std::max(z, 0ll);
    }
    
    ll lowerBound(ll x) {
        
        Node* y = this -> root;
        
        ll z = inf;
        
        while (y != tNil) {
            
            if (x >= y -> data) {
                
                z = y -> data;
                y = y -> right;
            } else {
                
                y = y -> left;
            }
        }
        
        return z;
    }
    
    ll upperBound(ll x) {
        
        Node* y = this -> root;
        
        ll z = inf;
        
        while (y != tNil) {
            
            if (x > y -> data) {
                
                z = y -> data;
                y = y -> right;
            } else {
                
                y = y -> left;
            }
        }
        
        return z;
    }
    
    ll osSelect(Node* x, ll i) {
        
        ll r = x -> left -> size + 1;
        
        if (i == r) {
            
            return x -> data;
        } else if (i < r) {
            
            return osSelect(x -> left, i);
        } else {
            
            return osSelect(x -> right, i - r);
        }
    }
    
    ll osRank(Node* x) {
        
        ll r = x -> left -> size + 1;
        
        Node* y = x;
        
        while (y != this -> root) {
            
            if (y == y -> parent -> right) {
                
                r += y -> parent -> left -> size + 1;
            }
            
            y = y -> parent;
        }
        
        return r;
    }
    
    ll size() {
        
        return cnt;
    }
    
    void inOrder() {
        
        inOrderHelper(this -> root);
    }
};
