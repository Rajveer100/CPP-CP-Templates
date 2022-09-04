class Sparse {
    
    std::vector<std::vector<ll>> sp;
    
public:
    
    void buildSparse(ll n, std::vector<ll> a) {
        
        ll maxLog = 21;
        this -> sp.resize(n, std::vector<ll> (maxLog));
        
        for (int i = 0; i <= n - 1; i++) {
            
            this -> sp[i][0] = a[i];
        }
        
        for (ll i = 1; i <= maxLog; i++) {
            
            for (ll j = 0; j + (1ll << i) - 1 <= n - 1; j++) {
                
                this -> sp[j][i] = std::max(sp[j][i - 1], sp[j + (1ll << (i - 1))][i - 1]);
            }
        }
    }
    
    ll query(ll l, ll r) {
        
        ll len = r - l + 1, k = ll((log2(len * 1.0)));
        
        return std::max(sp[l][k], sp[r - (1ll << k) + 1][k]);
    }
};
