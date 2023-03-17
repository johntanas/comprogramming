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
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<ll> v(n);
	for (auto &i:v){
		cin>>i;
	}
	vector<pll> p(n);
	for (int i=0;i<n;i++){
		cin>>a;
		p[i]=mp(a,v[i]);
	}
	sort(all(p));
	a=0;
	b=0;
	c=0;
	for (int i=0;i<n;i++){
		if (p[i].fi==-1){
			continue;
		}
		c=p[i].fi;
		b+=p[i].se;
		a=max((b-1)/c+1,a);
	}
	cout<<a;
}