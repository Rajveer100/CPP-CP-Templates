class DSU {
    
public:
    
    ll maxSize;
    std::vector<ll> p, size;
    
    DSU(ll maxSize) {
        
        this -> maxSize = maxSize;
        
        this -> p.resize(maxSize + 5);
        this -> size.resize(maxSize + 5);
        
        for (int i = 1; i <= maxSize - 1; i++) {
            
            this -> p[i] = i;
            this -> size[i] = 1;
        }
    }
    
    ll findSet(ll v) {
        
        if (v == this -> p[v]) {
            
            return v;
        }
        
        return findSet(this -> p[v]);
    }
    
    void unionSets(ll u, ll v) {
        
        u = findSet(u);
        v = findSet(v);
        
        if (u != v) {
            
            if (this -> size[u] < this -> size[v]) {
                
                std::swap(u, v);
            }
            
            this -> p[v] = u;
            this -> size[u] += this -> size[v];
        }
    }
};
