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
const int INF = (int)1e9;
ll n, m, t, a, b, c, k;
string f, s;
vector<ll> p;
ll memo[40][1001];
ll dp(int i,ll r){
	if (i==n){
		if (r!=0){
			return INF;
		} else {
			return 0;
		}
	}
	ll &ans = memo[i][r];
	if (ans!=-1){return ans;}
	if (r>=p[i]){
		return ans = min(max(dp(i+1,r+p[i]),r+p[i]),max(dp(i+1,r-p[i]),r));
	}
	return ans =max(dp(i+1,r+p[i]),r+p[i]);
}
void solve(){
	cin >> n;
	p.clear();
	memset(memo,-1,sizeof memo);
	for (int i=0;i<n;i++){
		cin>>a;
		p.pb(a);
	}
	ll best =dp(0,0);
	if (best==INF){
		cout<< "IMPOSSIBLE"<<nl;
		return;
	}
	ll curr=0;
	for (int i=0;i<n-1;i++){
		if (p[i]<=curr &&memo[i+1][curr+p[i]]>memo[i+1][curr-p[i]]){
			cout<<"D";
			curr-=p[i];
		} else{
			curr+=p[i];
			cout<<"U";
		}
	}
	cout<<"D"<<nl;
}
int TC;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> TC;
	while (TC-->0){
		solve();
	}
}