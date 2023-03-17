#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll t, b;
ll _sieve_size;
bitset<10000010> comp;
vector<ll> p;
void sieve(ll upperbound){
	_sieve_size = upperbound+1;
	comp.set();
	comp[0]=comp[1]=0;
	for (ll i=2;i<_sieve_size;i++){
		if (comp[i]){
			for (ll j=i*i;j<_sieve_size;j+=i){
				comp[j] =0;
			}
			p.push_back(i);
		}
	}
}
bool isPrime(ll N){
	if (N<_sieve_size){
		return comp[N];
	}
	for (int i=0;i<(int)p.size() &&p[i]*p[i]<=N;i++){
		if (N%p[i] ==0){
			return false;
		}
	}
	return true;
}
int main(){
	cin >> t;
	sieve(50000);
	while (t){
		b=2*t+1;
		while (true){
			if (isPrime(b)){
				break;
			}
			b++;
		}
		cout << b <<" ";
		if (!isPrime(t)){
			cout << "("<<t<<" is not prime)";
		}
		cout <<"\n";
		cin >> t;
	}
}