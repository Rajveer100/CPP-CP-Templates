template<typename T>
class Fenwick {
  std::vector<T> fenwick;
public:
  
  Fenwick(T n) {
    this -> fenwick.resize(n + 5, 0);
  }
  
  T query(T pos) {
    pos++;
    T s = 0;
    
    while (pos > 0) {
      s += this -> fenwick[pos];
      pos -= pos & (-pos);
    }
    
    return s;
  }
  
  void updateTree(T n, T pos, T val) {
    pos++;
    
    while (pos <= n) {
      this -> fenwick[pos] += val;
      pos += pos & (-pos);
    }
  }
};
