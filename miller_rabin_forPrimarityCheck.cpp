#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Calculates (a^d) % mod using binary exponentiation
ll power(ll a, ll d, ll mod) {
    ll res = 1;

    while(d) {
        // If current bit of d is 1, multiply by a
        if(d & 1)
            res = (__int128)res * a % mod;

        // Square a for the next bit
        a = (__int128)a * a % mod;

        // Move to the next bit
        d >>= 1;
    }

    return res;
}

// Checks whether n is prime using Miller-Rabin
bool isprime(ll n) {
    if(n < 2) return false;

    // Check divisibility by small primes first
    for(ll p : {2LL, 3LL, 5LL, 7LL, 11LL, 13LL, 17LL, 19LL, 23LL, 29LL, 31LL, 37LL}) {
        if(n % p == 0)
            return n == p;
    }

    // Write n - 1 as d * 2^s, where d is odd
    ll d = n - 1;
    int s = 0;

    while((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    // Test n using several bases
    for(ll a : {2LL, 3LL, 5LL, 7LL, 11LL, 13LL, 17LL}) {
        if(a >= n) continue;

        // Calculate a^d % n
        ll x = power(a, d, n);

        // Test passed for this base
        if(x == 1 || x == n - 1)
            continue;

        bool ok = false;

        // Keep squaring x and check whether we get n - 1
        for(int r = 1; r < s; r++) {
            x = (__int128)x * x % n;

            if(x == n - 1) {
                ok = true;
                break;
            }
        }

        // Test failed, so n is composite
        if(!ok)
            return false;
    }

    // All tests passed, so n is prime
    return true;
}

void solve() {
    ll n;
    cin >> n;

    // Start checking from the next number
    n++;

    // Find the next prime number
    while(!isprime(n))
        n++;

    cout << n << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
        solve();
}