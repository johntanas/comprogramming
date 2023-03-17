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
int TC;
vector<int> visited;
vector<pii> v;
vector<vector<int>> al;
void dfs(int u){
	visited[u]=1;
	for (int v:al[u]){
		if (!visited[v]){
			dfs(v);
		}
	}
}
int dist(pii f, pii s){
	return abs(f.fi-s.fi)+abs(s.se-f.se);
}
void solve(){
	cin>> n;
	visited.assign(n+2,0);
	v.resize(n+2);
	for (int i=0;i<n+2;i++){
		cin>> a>>b;
		v[i]={a,b};
	}
	al.assign(n+2,{});
	for (int i=0;i<n+2;i++){
		for (int j=i+1;j<n+2;j++){
			if (dist(v[i],v[j])<=1000){
				al[i].pb(j);
				al[j].pb(i);
			}
		}
	}
	dfs(0);
	(visited[n+1]) ? printf("happy\n") : printf("sad\n");
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> TC;
	while (TC--){
		solve();
	}
}