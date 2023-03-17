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
const int mod = 1e9+7;
ll memo[101][10001];
ll dp(int j,int r){
	if (r<0){
		return 0;
	}
	if (j==a){
		return 1;
	}
	ll &ans = memo[j][r];
	if (ans!=-1){return ans;}
	ans=0;
	for (ll i=0;i<=b;i++){
		ans+=dp(j+1,r-i);
		ans %= mod;
	}
	ans %= mod;
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>a>>b;
	memset(memo,-1,sizeof memo);
	ll ans = dp(0,n);
	ll plains = (min(a*b,n)/a+1);
	cout<< (ans-plains+mod)%mod;
}