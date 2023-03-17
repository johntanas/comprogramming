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
const int MAXC =2001, MAXN=2001;
int dp[MAXN][MAXC];
int v[MAXN];
int w[MAXN];
// idk why topdown dp does not work???
void d(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=c;j++){
			if (j>=w[i-1]){
				dp[i][j]=max(dp[i-1][j-w[i-1]]+v[i-1],dp[i-1][j]);
			} else {
				dp[i][j]=dp[i-1][j];
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> c && cin>> n){
		memset(dp,0,sizeof dp);
		for (int i=0;i<n;i++){
			cin>> v[i]>> w[i];
		}
		d();
		vector<int>p;
		int i = n,j=c;
		while (i &&j){
			if (dp[i][j]==0) break;
			if (dp[i][j]==dp[i-1][j]){
				i--;
			} else {
				i--;
				j-=w[i];
				p.pb(i);
			}
		}
		cout << p.size()<<nl;
		if (p.size()){
			for (int i:p){
				cout << i<< " ";
			}
			cout<<nl;
		}
	}
}