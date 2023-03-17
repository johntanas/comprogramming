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
string f, s,tt;
vector<int> in;
vector<int> out;
vector<vector<int>> al;
vector<int> visited;
int ti=1;
int dfs(int u){
	int ok =0;
	if (visited[u]==ti){
		return 1;
	}
	if (visited[u]){
		return 0;
	}
	visited[u]=ti;
	for (int v:al[u]){
		ok=dfs(v);
	}
	if (ok){
		return ok+1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	unordered_map<string,int> ma;
	al.assign(n,{});
	int pos=1;
	for (int i=0;i<n;i++){
		for (int d=0;d<3;d++){
			cin>>f;
			if (!ma[f]){
				ma[f]=pos++;
			}
			if (d==1){
				in.pb(ma[f]);
			}
			if (d==2){
				out.pb(ma[f]);
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (out[i]==in[j]){
				al[i].pb(j);
				break;
			}
		}
	}
	int out=0;
	visited.assign(n,0);
	for (int i=0;i<n;i++){
		if(!visited[i]){
			out=max(dfs(i),out);ti++;
		}
	}
	if (out>1){
		cout<<out-1;
	} else {
		cout<<"No trades possible";
	}
}