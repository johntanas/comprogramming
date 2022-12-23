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
void solve(){
	cin >> n>>m;
	vector<int> v(n);
	for (int i=0;i<n;i++){
		cin >> v[i];
	}
	ll best=0;
	ll run=0;
	ll pre=0;
	for (int i:v){
		if (i<m){
			if (run){
				best=max(best,run+pre);
			}
			pre=0;
			run=0;
		} else if (i==m){
			best=max(best,run+pre);
			run = i+pre;
			pre=0;
		} else {
			pre+=i;
		}
	}
	cout << max(best,run+pre)<<nl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TC;
	cin >> TC;
	while (TC-->0){
		solve();
	}
}