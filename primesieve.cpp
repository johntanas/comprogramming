#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vll = vector<ll>;
ll _sieve_size;
bitset<100000001> bs;
ll coun;
void sieve(ll upperbound){
    _sieve_size = upperbound +1;
    bs.set();
    bs[0] = bs[1] =0;
    for (ll i=2;i<_sieve_size;++i){
        if (bs[i]){
            for (ll j =i*i;j<_sieve_size;j+=i){
                bs[j] =0;
            }
            coun++;
        }
    }
}
bool isPrime(ll N){
    return bs[N];
}
int main() {
    int n,q;
    cin >> n >> q;
    sieve(n);
    printf("%d\n",coun);
    while (q-->0){
        cin >> n;
        printf("%d\n",isPrime(n));
    }
}
