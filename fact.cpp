long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
ll modinv(ll a,ll m){
    return binpow(a,m-2,m);
}
 
ll mygcd(ll x, ll y){
    return y == 0 ? x : mygcd(y, x % y);
}
 
const int MAX=1e6+5;
ll fact[MAX], invFact[MAX];
 
void initFactorials() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = fact[i - 1] * i % MOD;
    invFact[MAX - 1] = binpow(fact[MAX - 1], MOD - 2, MOD);
    for (int i = MAX - 2; i >= 1; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}
 
ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}