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
	int memo[n+m+2]={0};
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			memo[i+j]++;
		}
	}
	int out=0;
	vector<int> v;
	for (int i=0;i<n+m+2;i++){
		if (memo[i]==out){
			v.pb(i);
		}
		if (memo[i]>out){
			v.clear();
			out=memo[i];
			v.pb(i);
		}
	}
	for (int i:v){
		cout<<i<<nl;
	}
}