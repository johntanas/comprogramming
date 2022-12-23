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
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << nl

ll n, m, t, a, b, c, k;
string f, s;
bitset<1000010> bs;
vector<ll> p;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	bs.set();
	bs[0]=bs[1]=0;
	for (ll i=2;i<50000;i++){
		if (bs[i]){
			for (ll j=i*i;j<50000;j+=i){
				bs[j]=0;
			}
			p.pb(i);
		}
	}
	cin >> n;
	while (n){
		ll ans =n;
		for (int i=0;i<p.size()&&p[i]*p[i]<=n;i++){
			if(n%p[i]==0) {ans-=ans/p[i];}
			while (n%p[i]==0){n/=p[i];}
		}
		if (n!=1) {ans-=ans/n;}
		cout<<ans <<nl;
		cin>>n;
	}
}