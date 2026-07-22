//ncr binpw
//! In The Name Of Allah

#include <bits/stdc++.h>
using namespace std;
#define itr(i, a) for (int i = 0; i < a; i++)
#define ittr(i, bg, a) for (int i = bg; i < a; i++)
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ll long long
#define endd cout << endl
#define vc(v, n) vector<ll> v(n)
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define MOD 1000000007
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define f first
#define sc second
const int N = 1e6 + 1;
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
void solve()
{
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ts = 1;
    cin >> ts;
    while (ts--)
    {
        solve();
    }
}