std::vector<ll> fact(2e5+5);
std::vector<ll> inv(2e5+5), invFact(2e5+5);

void preCalc(ll m) {
    
    fact[0]=fact[1]=1;
    inv[1]=1;
    invFact[0]=invFact[1]=1;
    
    for(int i=2;i<=2e5;i++) {
        
        fact[i]=(fact[i-1]*i)%m;
        inv[i]=m-((m/i)*inv[m%i])%m;
        invFact[i]=(invFact[i-1]*inv[i])%m;
    }
}

ll binExp(ll a, ll b, ll m) {
    
    ll res=1, mul=a;
    
    while(b) {
        
        if(b&1) {
            
            res=(res*mul)%m;
        }
        
        mul=(mul*mul)%m;
        b>>=1;
    }
    
    return res;
}

ll nCr(ll n, ll r, ll m) {
    
    if(n<0 || r<0 || r>n) {
        
        return 0;
    }
    
    return (((fact[n]*invFact[r])%m)*invFact[n-r])%m;
}

ll nCrMini(ll n, ll r) {
    
    if(n<0 || r<0 || r>n) {
        
        return 0;
    }
    
    std::vector<std::vector<ll>> c(n+1, std::vector<ll> (r+1, 0));
    
    for(ll i=0;i<=n;i++) {
        
        for(ll j=0;j<=std::min(i, r);j++) {
            
            if(!j || j==i) {
                
                c[i][j]=1;
            } else {
                
                c[i][j]=c[i-1][j-1]+c[i-1][j];
            }
        }
    }
    
    return c[n][r];
}

ll der(ll n) {
    
    std::vector<ll> d(n+5);
    
    d[1]=0;
    d[2]=1;
    
    for(int i=3;i<=n;i++) {
        
        d[i]=(i-1)*(d[i-1]+d[i-2]);
    }
    
    return d[n];
}
