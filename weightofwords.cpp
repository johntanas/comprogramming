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
int memo[41][1002];
int parent[41];
int dp(int i,int r){
	int &ans = memo[i][r];
	if (i==n){
		if (r==0){
			return ans=1;
		} else {
			return ans=0;
		}
	}
	if (r==0){
		return ans=0;
	}
	if (ans!=-1){return ans;}
	ans =0;
	for (int j=1;j<=26;j++){
		if (r>=j){
			int out =dp(i+1,r-j);
			ans=max(out,ans);
			if (out){
				parent[i]=j;
			}
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;
	memset(memo,-1,sizeof memo);
	int out = dp(0,m);
	if (out){
		for (int i=0;i<n;i++){
			cout<< (char)(parent[i]-1+'a');
		}
	} else {
		cout<< "impossible";
	}
}