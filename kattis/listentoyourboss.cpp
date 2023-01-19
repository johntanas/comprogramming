#include <bits/stdc++.h>
//-D_GLIBCXX_DEBUG -fsanitize=undefined
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
unordered_set<int> seen;
vector<vector<int>> al;
multimap<ll,pii> queries;
vector<int> ans;
void dfs(int u){
	auto out=queries.find(u);
	while (out!=queries.end()){
		auto val = out->se;
		if (seen.count(val.fi)){
			ans[val.se]=1;
		} else {
			ans[val.se]=0;
		}
		queries.erase(out);
		out=queries.find(u);
	}
	seen.insert(u);
	for (int v:al[u]){
		dfs(v);
	}
	seen.erase(seen.find(u));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;
	al.assign(n,{});
	for (int i=1;i<n;i++){
		cin>>a;
		a--;
		al[a].pb(i);
	}
	ans.resize(m);
	while (m--){
		cin >>a>>b;
		a--;b--;
		queries.insert({a,{b,m}});
	}
	dfs(0);
	for (auto it = ans.rbegin();it!=ans.rend();it++){
		printf("%s\n",(*it) ? "No":"Yes");
	}
}