vector<long long> getDivisors(long long n) {
    vector<long long> d;

    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);

            if (i != n / i)
                d.push_back(n / i);
        }
    }

    sort(d.begin(), d.end());
    return d;
}

vector<vector<int>> getDivisors(int n) {
    vector<vector<int>> divisors(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            divisors[j].push_back(i);
        }
    }

    return divisors;
}