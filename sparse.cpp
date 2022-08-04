class Sparse {
    
    std::vector<std::vector<ll>> sp;
    std::string type;
    
public:
    
    Sparse(std::string type) {
        
        this->type=type;
    }
    
    void buildSparse(ll n, std::vector<ll> a) {
        
        ll maxLog=21;
        this->sp.resize(n, std::vector<ll> (maxLog));
        
        for(int i=0;i<=n-1;i++) {
            
            this->sp[i][0]=a[i];
        }
        
        for(ll i=1;i<=maxLog;i++) {
            
            for(ll j=0;j+(1ll<<i)-1<=n-1;j++) {
                
                if(this->type=="max") {
                    
                    this->sp[j][i]=std::max(sp[j][i-1], sp[j+(1ll<<(i-1))][i-1]);
                } else if(this->type=="min") {
                    
                    this->sp[j][i]=std::min(sp[j][i-1], sp[j+(1ll<<(i-1))][i-1]);
                } else {
                    
                    this->sp[j][i]=std::gcd(sp[j][i-1], sp[j+(1ll<<(i-1))][i-1]);
                }
            }
        }
    }
    
    ll query(ll l, ll r) {
        
        ll len=r-l+1, k=ll((log2(len*1.0)));
        
        if(this->type=="max") {
            
            return std::max(sp[l][k], sp[r-(1ll<<k)+1][k]);
        } else if(this->type=="min") {
            
            return std::min(sp[l][k], sp[r-(1ll<<k)+1][k]);
        } else {
            
            return std::gcd(sp[l][k], sp[r-(1ll<<k)+1][k]);
        }
    }
};