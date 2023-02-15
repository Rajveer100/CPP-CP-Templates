template<typename T>
class DSU {
 public:
  T maxSize;
  std::vector<T> p, size;
  
  DSU(T maxSize) {
    maxSize = maxSize;
    p.resize(maxSize);
    size.resize(maxSize);
    
    for (T i = 0; i < maxSize; i += 1) {
      p[i] = i;
      size[i] = 1;
    }
  }
  
  T findSet(T v) {
    if (v == p[v]) {
      return v;
    }
    return findSet(p[v]);
  }
  
  void unionSets(T u, T v) {
    u = findSet(u);
    v = findSet(v);
    
    if (u != v) {
      if (size[u] < size[v]) {
        std::swap(u, v);
      }
      p[v] = u;
      size[u] += size[v];
    }
  }
};
