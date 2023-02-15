std::vector<mint> fact(LIM), invFact(LIM);

void preCalcCombi() {
  fact[0] = fact[1] = 1;
  invFact[0] = invFact[1] = 1;
  
  for (int i = 2; i < LIM; i += 1) {
    fact[i] = fact[i - 1] * i;
    invFact[i] = (mint) 1 / fact[i];
  }
}

mint binExp(mint a, long long b) {
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

mint C(long long n, long long r) {
  if (n < 0 || r < 0 || r > n) {
    return 0;
  }
  
  return fact[n] * invFact[r] * invFact[n - r];
}

mint der(long long n) {
  std::vector<mint> d(n + 1);
  d[1] = 0;
  d[2] = 1;
  
  for (int i = 3; i <= n; i += 1) {
    d[i] = (long long) (i - 1) * (d[i - 1] + d[i - 2]);
  }
  
  return d[n];
}
