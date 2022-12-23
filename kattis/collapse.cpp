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
	cin >> n;
	int cost[n];
	int left[n]={0};
	vector<vector<pii>> al;
	al.resize(n,{});
	for (int i=0;i<n;i++){
		cin>> cost[i]>>b;
		int u,w;
		for (int j=0;j<b;j++){
			cin >> u>>w;
			al[u-1].pb(pii(i,w));
			left[i]+=w;
		}
	}
	queue<int> q;
	q.push(0);
	bool alive[n];
	fill(alive,alive+n,true);
	alive[0]=false;
	while (!q.empty()){
		int min =q.front();q.pop();
		for (pii i:al[min]){
			left[i.fi]-=i.se;
			if (left[i.fi]<cost[i.fi] && alive[i.fi]){
				alive[i.fi]=false;
				q.push(i.fi);
			}
		}
	}
	cout<<accumulate(alive,alive+n,0);
}