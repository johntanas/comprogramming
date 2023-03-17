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
vector<vector<pii>> al;
priority_queue<pii> pq;
vector<int> visited;
int prim(){
	int out=-1;
	for (pii p:al[0]){
		pq.push(p);
	}
	visited[0]= 1;
	while (!pq.empty()){
		auto min = pq.top();pq.pop();
		if (!visited[min.se]){
			out =min.fi;
			visited[min.se]=1;
			for (pii p:al[min.se]){
				pq.push(p);
			}
		}
	}
	return out;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;
	visited.resize(n,0);
	al.resize(n,{});
	for (int i=0;i<m;i++){
		int u,v,w;
		cin>> u>>v>>w;
		al[u].pb(pii(-w,v));
		al[v].pb(pii(-w,u));
	}
	int out=prim();
	for (int i:visited){
		if (!i){
			cout<<"IMPOSSIBLE";
			return 0;
		}
	}
	cout<< out*-1;
}