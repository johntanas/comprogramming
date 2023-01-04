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
vector<vector<int>> al;
vector<int> marbles;
vector<int> root;
ll ans=0;
ll dfs(int u){
	ll out=marbles[u];
	for (int v:al[u]){
		out+=dfs(v);
	}
	ans+=abs(out);
	return out;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n&&n){
		ans=0;
		al.clear();
		marbles.clear();
		al.resize(n,{});
		marbles.resize(n);
		root.resize(n,0);
		for (int i=0;i<n;i++){
			cin >> a >> b>>c;
			a--;
			b--;
			marbles[a]=b;
			while(c--){
				int v;
				cin >> v;
				v--;
				al[a].pb(v);
				root[v]++;
			}
		}
		for (int i=0;i<n;i++){
			if (!root[i]){
				dfs(i);
				break;
			}
		}
		cout<<ans<<nl;
	}
}