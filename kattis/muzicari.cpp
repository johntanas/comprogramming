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
vector<int> v;
int memo[501][5001];
int dp(int id,int r){
	if (id==n || r==0){return 0;}
	int &ans = memo[id][r];
	if (ans!=-1){return ans;}
	if (r<v[id]) return ans = dp(id+1,r);
	return ans=max(dp(id+1,r-v[id])+v[id],dp(id+1,r));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>t>> n;
	for(int i=0;i<n;i++){
		cin>>a;
		v.pb(a);
	}
	memset(memo,-1,sizeof memo);
	int best=dp(0,t);
	int st=0;
	for (int i=0;i<n;i++){
		if (memo[i][t]==memo[i+1][t]){
			cout<< st<<" ";
			st+=v[i];
		} else{
			t-=v[i];
			cout<< t<<" ";
		}
	}
}