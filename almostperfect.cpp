#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()
 
ll n, m, t, a, b, k;
bitset<100010> bs;
vector<ll> p;
ll sumDiv(ll N){
	ll ans=1;
	for (int i=0;i<p.size()&& p[i]*p[i]<=N;i++){
		ll mu =p[i], total =1;
		while (N%p[i] ==0){
			N/=p[i];
			total+= mu;
			mu*=p[i];
		}
		ans*= total;
	}
	if (N!=1){ans*=(N+1);}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	bs[0] =bs[1]=0;
	bs.set();
	for (ll i=2;i<50000;i++){
		if (bs[i]){
			for (ll j =i*i;j<50000;j+=i){
				bs[j]=0;
			}
			p.pb(i);
		}
	}
	cin >> n;
	while (!cin.eof()){
		ll out = sumDiv(n)-n;
		if (n==out){
			cout << n<< " perfect"<<nl;
		} else if(abs(n-out)<=2){
			cout << n<< " almost perfect"<<nl;
		} else {
			cout << n<< " not perfect"<<nl;
		}
		cin >> n;
	}
}