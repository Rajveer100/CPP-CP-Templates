std::vector<mint> fact(lim), invFact(lim);

void preCalcCombi() {
    
    fact[0] = fact[1] = 1;
    invFact[0] = invFact[1] = 1;
    
    for (ll i = 2; i <= lim - 1; i++) {
        
        fact[i] = fact[i - 1] * i;
        invFact[i] = (mint) 1 / fact[i];
    }
}

mint binExp(mint a, ll b) {
    
    mint res = 1;
    
    while (b > 0) {
        
        if (b & 1) {
            
            res *= a;
        }
        
        a *= a;
        b >>= 1;
    }
    
    return res;
}

mint C(ll n, ll r) {
    
    if (n < 0 || r < 0 || r > n) {
        
        return 0;
    }
    
    return fact[n] * invFact[r] * invFact[n - r];
}

mint der(ll n) {
    
    std::vector<mint> d(n + 5);
    
    d[1] = 0;
    d[2] = 1;
    
    for (ll i = 3; i <= n; i++) {
        
        d[i] = (i - 1) * (d[i - 1] + d[i - 2]);
    }
    
    return d[n];
}
