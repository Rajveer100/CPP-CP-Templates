class SegTree {
    
    std::vector<ll> segTree, lazy;
    std::string type;

public:    

    SegTree(std::string type) {
        
        this->type=type;
    }
    
    void buildTree(ll &n, std::vector<ll> a) {
        
        ll num=n;
        
        n=(1ll<<ll(std::ceil(log2(n*1.0))));
        
        this->segTree.resize(2*n);
        this->lazy.resize(2*n);
        
        for(ll i=0;i<=num-1;i++) {
            
            this->segTree[n+i]=a[i];
        }
        
        for(ll i=num;i<=n-1;i++) {
            
            if(this->type=="min") {
                
                this->segTree[n+i]=inf;
            } else {
                
                this->segTree[n+i]=0;
            }
        }
        
        for(ll i=n-1;i>=1;i--) {
            
            if(this->type=="sum") {
                
                this->segTree[i]=this->segTree[2*i]+this->segTree[2*i+1];
            } else if(this->type=="min") {
                
                this->segTree[i]=std::min(this->segTree[2*i], this->segTree[2*i+1]);
            } else if(this->type=="max") {
                
                this->segTree[i]=std::max(this->segTree[2*i], this->segTree[2*i+1]);
            } else if(this->type=="gcd") {
                
                this->segTree[i]=std::gcd(this->segTree[2*i], this->segTree[2*i+1]);
            }
        }
    }
    
    ll rangeQuery(ll node, ll left, ll right, ll l, ll r) {
        
        if(this->lazy[node]) {
            
            this->segTree[node]+=this->lazy[node]*(right-left+1);
            
            if(left!=right) {
                
                this->lazy[2*node]+=this->lazy[node];
                this->lazy[2*node+1]+=this->lazy[node];
            }
            
            this->lazy[node]=0;
        }
        
        if(left>=l && right<=r) {
            
            return this->segTree[node];
        } else if(right<l || left>r) {
            
            if(this->type=="min") {
                
                return inf;
            }
            
            return 0;
        } else {
            
            ll mid=(left+right)/2;
            
            if(this->type=="sum") {
                
                return rangeQuery(2*node, left, mid, l, r)+rangeQuery(2*node+1, mid+1, right, l, r);
            } else if(this->type=="min") {
                
                return std::min(rangeQuery(2*node, left, mid, l, r), rangeQuery(2*node+1, mid+1, right, l, r));
            } else if(this->type=="max") {
                
                return std::max(rangeQuery(2*node, left, mid, l, r), rangeQuery(2*node+1, mid+1, right, l, r));
            }
            
            return std::gcd(rangeQuery(2*node, left, mid, l, r), rangeQuery(2*node+1, mid+1, right, l, r));
        }
    }
    
    void pointUpdate(ll n, ll pos, ll newVal) {
        
        this->segTree[n+pos]=newVal;
        
        for(ll j=(n+pos)/2;j>=1;j/=2) {
            
            if(this->type=="sum") {
                
                this->segTree[j]=this->segTree[2*j]+this->segTree[2*j+1];
            } else if(this->type=="min") {
                
                this->segTree[j]=std::min(this->segTree[2*j], this->segTree[2*j+1]);
            } else if(this->type=="max") {
                
                this->segTree[j]=std::max(this->segTree[2*j], this->segTree[2*j+1]);
            } else if(this->type=="gcd") {
                
                this->segTree[j]=std::gcd(this->segTree[2*j], this->segTree[2*j+1]);
            }
        }
    }
    
    void rangeUpdate(ll node, ll left, ll right, ll l, ll r, ll newVal) {
        
        if(this->lazy[node]) {
            
            this->segTree[node]+=this->lazy[node]*(right-left+1);
            
            if(left!=right) {
                
                this->lazy[2*node]+=this->lazy[node];
                this->lazy[2*node+1]+=this->lazy[node];
            }
            
            this->lazy[node]=0;
        }
        
        if(left>=l && right<=r) {
            
            this->segTree[node]+=newVal*(right-left+1);
            
            if(left!=right) {
                
                this->lazy[2*node]+=newVal;
                this->lazy[2*node+1]+=newVal;
            }
        } else if(right<l || left>r) {
            
            return;
        } else {
            
            ll mid=(left+right)/2;
            
            rangeUpdate(2*node, left, mid, l, r, newVal);
            rangeUpdate(2*node+1, mid+1, right, l, r, newVal);
            
            if(this->type=="sum") {
                
                this->segTree[node]=this->segTree[2*node]+this->segTree[2*node+1];
            } else if(this->type=="min") {
                
                this->segTree[node]=std::min(this->segTree[2*node], this->segTree[2*node+1]);
            } else if(this->type=="max") {
                
                this->segTree[node]=std::max(this->segTree[2*node], this->segTree[2*node+1]);
            } else if(this->type=="gcd") {
                
                this->segTree[node]=std::gcd(this->segTree[2*node], this->segTree[2*node+1]);
            }
        }
    }
};

