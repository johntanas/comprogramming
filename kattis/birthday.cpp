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
int memo[100];
vector<vector<int>> al;
int lvl[100];
int bridges;
void dfs(int u){
	memo[u]=0;
	for (int v:al[u]){
		if (lvl[v]==-1){
			lvl[v]=lvl[u]+1;
			dfs(v);
			memo[u]+=memo[v];
		} else if (lvl[v]<lvl[u]){
			memo[u]++;
		} else if (lvl[v] > lvl[u]){
			memo[u]--;
		}
	}
	memo[u]--;
	if (lvl[u]>1 && memo[u]==0){
		bridges++;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n>>m && n){
		bridges=0;
		memset(memo,-1,sizeof memo);
		memset(lvl,-1,sizeof lvl);
		al.clear();
		al.resize(n,{});
		for (int i=0;i<m;i++){
			int u,v;
			cin >> u>>v;
			al[u].pb(v);
			al[v].pb(u);
		}
		lvl[1]=1;
		dfs(1);
		int ok =0;
		for (int i=0;i<n;i++){
			if (lvl[i] ==-1){
				ok =1;
				break;
			}
		}
		if (bridges>0 || ok){
			cout<<"Yes";
		} else {
			cout<<"No";
		}
		cout<<nl;
	}
}