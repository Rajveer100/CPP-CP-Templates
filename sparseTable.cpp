template<typename T>
class SparseMax {
  std::vector<std::vector<T>> sp;
public:
  
  void buildSparse(T n, std::vector<T> a) {
    T maxLog = 21;
    sp.resize(n, std::vector<T> (maxLog));
    
    for (T i = 0; i < n; i += 1) {
      sp[i][0] = a[i];
    }
    
    for (T i = 1; i <= maxLog; i += 1) {
      for (T j = 0; j + (1 << i) - 1 < n; j += 1) {
        sp[j][i] = std::max(sp[j][i - 1], sp[j + (1 << (i - 1))][i - 1]);
      }
    }
  }
  
  T query(T l, T r) {
    T len = r - l + 1, k = (T) log2(len * 1.0);
    return std::max(sp[l][k], sp[r - (1 << k) + 1][k]);
  }
};

template<typename T>
class SparseMin {
  std::vector<std::vector<T>> sp;
public:
  
  void buildSparse(T n, std::vector<T> a) {
    T maxLog = 21;
    sp.resize(n, std::vector<T> (maxLog, 1e18));
    
    for (T i = 0; i < n; i += 1) {
      sp[i][0] = a[i];
    }
    
    for (T i = 1; i <= maxLog; i += 1) {
      for (T j = 0; j + (1 << i) - 1 < n; j += 1) {
        sp[j][i] = std::min(sp[j][i - 1], sp[j + (1 << (i - 1))][i - 1]);
      }
    }
  }
  
  T query(T l, T r) {
    T len = r - l + 1, k = (T) log2(len * 1.0);
    return std::min(sp[l][k], sp[r - (1 << k) + 1][k]);
  }
};

template<typename T>
class SparseGcd {
  std::vector<std::vector<T>> sp;
public:
  
  void buildSparse(T n, std::vector<T> a) {
    T maxLog = 21;
    sp.resize(n, std::vector<T> (maxLog));
    
    for (T i = 0; i < n; i += 1) {
      sp[i][0] = a[i];
    }
    
    for (T i = 1; i <= maxLog; i += 1) {
      for (T j = 0; j + (1 << i) - 1 < n; j += 1) {
        sp[j][i] = std::gcd(sp[j][i - 1], sp[j + (1 << (i - 1))][i - 1]);
      }
    }
  }
  
  T query(T l, T r) {
    T len = r - l + 1, k = (T) log2(len * 1.0);
    return std::gcd(sp[l][k], sp[r - (1 << k) + 1][k]);
  }
};
