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
int dfs_num[100000];
vector<vector<int>> al;
vector<vector<int>> al_t;
vector<int> ss;
int pos =1;
int dfs(int u,int pass){
	int ans=0;
	dfs_num[u]=pos;
	vector<int> &nei = (pass==1) ? al[u] : al_t[u];
	for (int v:nei){
		if (dfs_num[v]==-1){
			ans |=dfs(v,pass);
		} else if (dfs_num[v]!=dfs_num[u]){
			ans=1;
		}
	}
	ss.pb(u);
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t-->0){
		cin>> n>>m;
		ss.clear();
		memset(dfs_num,-1,sizeof dfs_num);
		al.clear();
		al_t.clear();
		al.resize(n,{});
		al_t.resize(n,{});
		pos=1;
		for (int i=0;i<m;i++){
			int u,v;
			cin>> u>>v;
			u--;
			v--;
			al[u].pb(v);
			al_t[v].pb(u);
		}
		for (int i=0;i<n;i++){
			if (dfs_num[i]==-1){
				dfs(i,1);
			}
		}
		ll numscc=0;
		memset(dfs_num,-1,sizeof dfs_num);
		for (int i=n-1;i>=0;i--){
			if (dfs_num[ss[i]]==-1){
				if (dfs(ss[i],2)==0){
					numscc++;
				}
				pos++;
			}
		}
		cout<<numscc<<nl;
	}
}