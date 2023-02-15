template<typename T>
class SegmentTree {
  std::vector<T> tree, lazy;
 public:
  
  void buildTree(T &n, std::vector<T> a) {
    T num = n;
    n = (1 << T(std::ceil(log2(n * 1.0))));
    tree.resize(2 * n);
    lazy.resize(2 * n);
    
    for (T i = 0; i <= num - 1; i++) {
      tree[n + i] = a[i];
    }
    for (T i = n - 1; i >= 1; i--) {
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
  }
  
  T rangeQuery(T node, T left, T right, T l, T r) {
    if (lazy[node]) {
      tree[node] += lazy[node] * (right - left + 1);
      if (left != right) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
    if (left >= l && right <= r) {
      return tree[node];
    } else if (right < l || left > r) {
      return 0;
    } else {
      T mid = (left + right) / 2;
      return rangeQuery(2 * node, left, mid, l, r) + rangeQuery(2 * node + 1, mid + 1, right, l, r);
    }
  }
  
  void pointUpdate(T n, T pos, T newVal) {
    tree[n + pos] = newVal;
    
    for (T j = (n + pos) / 2; j >= 1; j /= 2) {
      tree[j] = tree[2 * j] + tree[2 * j + 1];
    }
  }
  
  void rangeUpdate(T node, T left, T right, T l, T r, T newVal) {
    if (lazy[node]) {
      tree[node] += lazy[node] * (right - left + 1);
      if (left != right) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
    if (left >= l && right <= r) {
      tree[node] += newVal * (right - left + 1);
      if (left != right) {
        lazy[2 * node] += newVal;
        lazy[2 * node + 1] += newVal;
      }
    } else if (right < l || left > r) {
      return;
    } else {
      T mid = (left + right) / 2;
      
      rangeUpdate(2 * node, left, mid, l, r, newVal);
      rangeUpdate(2 * node + 1, mid + 1, right, l, r, newVal);
      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }
};
