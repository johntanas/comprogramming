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
int lvl[10000];
int dp[10000];
int dfs(int u){
	int ans=1;
	for (int v:al[u]){
		if (lvl[v]==-1){
			lvl[v]=lvl[u]+1;
			ans+=dfs(v);
			dp[u]+=dp[v];
		} else if (lvl[v]<lvl[u]){
			dp[u]++;
		} else if (lvl[v]>lvl[u]){
			dp[u]--;
		}
	}
	if (lvl[u]>1 && dp[u]==0){
		return 0;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;
	al.resize(n,{});
	memset(lvl,-1,sizeof lvl);
	memset(dp,-1,sizeof dp);
	for (int i=0;i<m;i++){
		int u,v;
		cin>> u>>v;
		al[u].pb(v);
		al[v].pb(u);
	}
	lvl[0]=1;
	cout<<dfs(0);
}