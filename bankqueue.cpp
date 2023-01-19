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
	cin >> n>>t;
	vector<vector<int>> v;
	v.resize(t,{});
	for (int i=0;i<n;i++){
		cin>>a>>b;
		v[b].pb(a);
	}
	for (int i=0;i<t;i++){
		sort(all(v[i]),greater());
	}
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i=0;i<t;i++){
		if (v[i].empty()){
			pq.push(0);
		} else {
			pq.push(v[i][0]);
		}
		for (int j=1;j<v[i].size();j++){
			if (v[i][j]>pq.top()){
				pq.pop();
				pq.push(v[i][j]);
			} else {
				break;
			}
		}
	}
	ll out=0;
	while (!pq.empty()){
		out+=pq.top();
		pq.pop();
	}
	cout<<out;
}