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
	cin >> n>>c;
	vector<ll> v(n);
	for (int i=0;i<n;i++){
		cin>>v[i];
	}
	int l=0,r=1,win=v[l];
	vector<ll> pre(n+1);
	pre.assign(n+1,0);
	while (r<n){
		if (win<=c){
			pre[l]++;
			pre[r]--;
		}
		while (r<n&&win+v[r]<=c){
			pre[l]++;
			pre[r+1]--;
			win+=v[r];
			r++;
		}
		win-=v[l];
		l++;
	}
	while (l<n){
		pre[l]++;
		l++;
	}
	for (int i=0;i<n;i++){
		cout<<pre[i]<<nl;
		pre[i+1]+=pre[i];
	}
}