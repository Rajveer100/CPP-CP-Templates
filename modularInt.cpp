template <long long MOD>
class Modular {
public:
  long long val;
  
  Modular(long long x = 0) {
    val = x % MOD;
    if (val < 0)
      val += MOD;
  }
  
  Modular& operator += (const Modular& x) {
    if ((val += x.val) >= MOD)
      val -= MOD;
    return *this;
  }
  
  Modular& operator -= (const Modular& x) {
    if ((val -= x.val) < 0)
      val += MOD;
    return *this;
  }
  
  Modular& operator *= (const Modular& x) {
    val = (val * x.val) % MOD;
    return *this;
  }
  
  Modular& operator /= (const Modular& x) {
    long long a = 0, b = 1, c = x.val;
    long long m = MOD;
    
    while (c != 0) {
      long long t = m / c;
      m -= (t * c);
      std::swap(c, m);
      a -= (t * b);
      std::swap(a, b);
    }
    
    a %= MOD;
    if (a < 0)
      a += MOD;
    val = (val * a) % MOD;
    
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

template <long long mod>
std::string to_string(const Modular<mod>& x) {
  return std::to_string(x.val);
}

template <long long mod>
std::ostream& operator << (std::ostream& stream, const Modular<mod> x) {
  return stream << x.val;
}

template <long long mod>
std::istream& operator >> (std::istream& stream, Modular<mod>& x) {
  stream >> x.val;
  x.val %= mod;
  if (x.val < 0)
    x.val += mod;
  
  return stream;
}

using mint = Modular<MOD1>;
