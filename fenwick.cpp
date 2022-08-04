class Fenwick {
    
    std::vector<ll> fenwick;
    
public:
    
    Fenwick(ll n) {
        
        this->fenwick.resize(n+5, 0);
    }
    
    ll query(ll pos) {
        
        pos++;
        
        ll s=0;
        
        while(pos>0) {
            
            s+=this->fenwick[pos];
            pos-=pos&(-pos);
        }
        
        return s;
    }
    
    void updateTree(ll n, ll pos, ll val) {
        
        pos++;
        
        while(pos<=n) {
            
            this->fenwick[pos]+=val;
            pos+=pos&(-pos);
        }
    }
};

