#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e6 + 5;

int mu[N];
int primes[N];
bool isComposite[N];
int cnt = 0;

// Calculates mu[1...N] in O(N)
void mobius() {
    mu[1] = 1;

    for(int i = 2; i < N; i++) {

        // i is prime
        if(!isComposite[i]) {
            primes[cnt++] = i;
            mu[i] = -1;
        }

        for(int j = 0; j < cnt && 1LL * i * primes[j] < N; j++) {
            int p = primes[j];

            isComposite[i * p] = true;

            // p^2 divides i*p
            if(i % p == 0) {
                mu[i * p] = 0;
                break;
            }

            // p is a new distinct prime factor
            mu[i * p] = -mu[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mobius();

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        cout << mu[n] << '\n';
    }
}