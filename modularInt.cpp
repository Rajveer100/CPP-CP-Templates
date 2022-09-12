template <ll mod>
class Modular {
    
public:
    
    ll val;
    
    Modular(ll x = 0) {
        
        val = x % mod;
        
        if (val < 0) val += mod;
    }
    
    Modular& operator += (const Modular& x) {
        
        if ((val += x.val) >= mod) val -= mod;
        
        return *this;
    }
    
    Modular& operator -= (const Modular& x) {
        
        if ((val -= x.val) < 0) val += mod;
        
        return *this;
    }
    
    Modular& operator *= (const Modular& x) {
        
        val = (val * x.val) % mod;
        
        return *this;
    }
    
    Modular& operator /= (const Modular& x) {
        
        ll a = 0, b = 1, c = x.val;
        ll m = mod;
        
        while (c != 0) {
            
            ll t = m / c;
            m -= (t * c);
            
            std::swap(c, m);
            
            a -= (t * b);
            
            std::swap(a, b);
        }
        
        a %= mod;
        
        if (a < 0) a += mod;
        val = (val * a) % mod;
        
        return *this;
    }
    
    friend Modular operator + (const Modular& l, const Modular& r) {
        
        return Modular(l) += r;
    }
    
    friend Modular operator - (const Modular& l, const Modular& r) {
        
        return Modular(l) -= r;
    }
    
    friend Modular operator * (const Modular& l, const Modular& r) {
        
        return Modular(l) *= r;
    }
    
    friend Modular operator / (const Modular& l, const Modular& r) {
        
        return Modular(l) /= r;
    }
    
    Modular& operator ++ () {
        
        return *this += 1;
    }
    
    Modular& operator -- () {
        
        return *this -= 1;
    }
    
    Modular operator ++ (int) {
        
        Modular z(*this);
        *this += 1;
        
        return z;
    }
    
    Modular operator -- (int) {
        
        Modular z(*this);
        *this -= 1;
        
        return z;
    }
    
    Modular operator - () const {
        
        return Modular(-val);
    }
    
    bool operator == (const Modular& r) const {
        
        return val == r.val;
    }
    
    bool operator != (const Modular& r) const {
        
        return val != r.val;
    }
    
    bool operator < (const Modular& r) const {
        
        return val < r.val;
    }
    
    bool operator > (const Modular& r) const {
        
        return val > r.val;
    }
};

template <ll mod>
std::string to_string(const Modular<mod>& x) {
    
    return std::to_string(x.val);
}

template <ll mod>
std::ostream& operator << (std::ostream& stream, const Modular<mod> x) {
    
    return stream << x.val;
}

template <ll mod>
std::istream& operator >> (std::istream& stream, Modular<mod>& x) {
    
    stream >> x.val;
    x.val %= mod;
    
    if (x.val < 0) x.val += mod;
    
    return stream;
}

using mint = Modular<mod1>;
