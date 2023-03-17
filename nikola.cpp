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
vector<int> p;
int memo[1001][1001];
int dp(int id,int r){
	if (id==p.size()-1) return 0;
	int &ans = memo[id][r];
	if (ans!=-1){return ans;}
	if (r==0){
		return ans=dp(id+r+1,r+1)+p[id+r+1];
	}
	if (id+r+1<p.size()&&id-r>=0){
		return ans =min(dp(id+r+1,r+1)+p[id+r+1],dp(id-r,r)+p[id-r]);
	}
	if (id+r+1<p.size()){
		return ans=dp(id+r+1,r+1)+p[id+r+1];
	}
	if (id-r>=0 && r!=0){
		return ans=dp(id-r,r)+p[id-r];
	}
	return (int) 1e8;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	memset(memo,-1,sizeof memo);
	for (int i=0;i<n;i++){
		cin>>a;
		p.pb(a);
	}
	cout << dp(0,0);
}