#include <bits/stdc++.h>
#define ll long long
#define MAX 1000007

using namespace std;

vector<ll> primes, seive(MAX, 0);

void FindPrimes() {
    primes.push_back(2);
    seive[0] = seive[1] = 1;
    for(ll i = 3; i < MAX; i += 2) {
        if(seive[i]) continue;
        primes.push_back(i);
        for(ll j = i*i; j < MAX; j += 2*i)
            seive[j] = 1;
    }
}

int main() {
    FindPrimes();
//    for(int i = 0; i < primes.size(); i++) cout << primes[i] << " ";

    int t; cin >> t;

    for(int i = 1; i <= t; i++) {
        ll n; cin >> n;
        ll sum = 1;

        for(int j = 0; j < primes.size(); j++) {
            if(primes[j]*primes[j] > n) break;
            if(n % primes[j]) continue;
            int k = 0;
            while( !(n % primes[j]) ) {
                k++;
                n /= primes[j];
            }
            sum *= k+1;
        }

        if(n != 1) sum *= 2;

        cout << "Case " << i << ": " << sum-1 << "\n";
    }

    return 0;
}

