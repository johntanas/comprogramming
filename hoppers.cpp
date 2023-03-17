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
	cin >> n>>m;
	vector<vector<int>> al;
	al.resize(n,{});
	for (int i=0;i<m;i++){
		int u,v;
		cin>> u>>v;
		u--;
		v--;
		al[u].pb(v);
		al[v].pb(u);
	}
	int color[n]={-1};
	fill(color,color+n,-1);
	int cc=0;
	int ok =0;
	for (int i=0;i<n;i++){
		if (color[i]==-1){
			queue<int> q;
			q.push(i);
			color[i]=1;
			while (!q.empty()){
				int min =q.front();q.pop();
				for (int u:al[min]){
					if (color[u] !=-1){
						if (color[u]==color[min]){
							ok =1;
						}
					} else {
						color[min] ? color[u]=0 : color[u]=1;
						q.push(u);
					}
				}
			}
			cc++;
		}
	}
	cout<< cc-ok;
}