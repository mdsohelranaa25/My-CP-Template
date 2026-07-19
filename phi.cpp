
vector<int> phi_from_1_to_n(int n) {
    vector<int>phi(n + 1, 1), sieve(n + 1, -1);
    
    for(int i = 2; i <= n; i++) {
        if(sieve[i] == -1) {
            sieve[i] = i;
            for(long long j = 1ll * i * i; j <= n; j += i)
                sieve[j] = i;
        }
    }
    
    for(int i = 2; i <= n; i++) {
        int p = sieve[i], j = i;
        while(j % p == 0) {
        	phi[i] *= p;
        	j /= p;
       	}
        //j is now equal to i / p^k
        phi[i] = (phi[i] / p) * (p - 1) * phi[j];
    }
    return phi;
}



// single element phi
ll calculate_phi(ll p){
    ll ans=p;
    for(ll i=2;i*i<=p;i++){
        if(p % i == 0){
            ans = ans / i * (i-1);
            while(p % i == 0) p/=i;
        }
    }
    if(p > 1){
        ans = ans / p * (p-1);
    }
    return ans;
}