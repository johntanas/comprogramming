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
vector<pll> po;
ll dp(ll j,ll r){
	if (j==po.size()){
		if (max((ll)a/r,r)<=n){
			return 1;
		}
		return 0;
	}
	ll ans=0;
	for (int i=0;i<=po[j].se;i++){
		ans+=dp(j+1,r);
		r*=po[j].fi;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;
	bs.set();
	bs[0]=bs[1]=0;
	for (ll i=2;i<1000001;i++){
		if (bs[i]){
			for (ll j=i*i;j<1000001;j+=i){
				bs[j]=0;
			}
			p.pb(i);
		}
	}
	a=m;
	for (ll i=0;i<p.size()&&p[i]*p[i]<=m;i++){
		int power =0;
		while (m%p[i]==0){
			m/=p[i];
			++power;
		}
		if (power){
			po.pb(pll(p[i],power));
		}
	}
	if (m!=1){
		po.pb(pll(m,1));
	}
	b=dp(0,1);
	cout<< b;
}