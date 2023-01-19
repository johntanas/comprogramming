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
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	vector<pll> v(n);
	for (int i=0;i<n;i++){
		cin>> a>>b;
		v[i]={a,a+b};
	}
	sort(all(v));
	c=0;
	for (int i=0;i<n;i++){
		while (!pq.empty()&&pq.top()+t<v[i].fi){
			pq.pop();
		}
		if (!pq.empty() && pq.top()+t>=v[i].fi&&v[i].fi>=pq.top()){
			pq.pop();
			c++;
		}
		pq.push(v[i].se);
	}
	cout<<c;
}