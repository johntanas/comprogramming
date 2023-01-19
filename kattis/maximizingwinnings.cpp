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
int memomax[50][5000];
int memomin[50][5000];
vector<vector<int>> al;
int dpmax(int i,int t){
	if (t==m){
		return 0;
	}
	int &ans = memomax[i][t];
	if (ans!=-1){return ans;}
	for (int j=0;j<n;j++){
		ans=max(ans,dpmax(j,t+1)+al[i][j]);
	}
	return ans;
}
const int INF = (1<<31)-1;
int dpmin(int i,int t){
	if (t==m){
		return 0;
	}
	int &ans = memomin[i][t];
	if (ans!=-1){return ans;}
	ans=INF;
	for (int j=0;j<n;j++){
		ans=min(ans,dpmin(j,t+1)+al[i][j]);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n&&n){
		al.clear();
		al.resize(n);
		memset(memomax,-1,sizeof memomax);
		memset(memomin,-1,sizeof memomin);
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cin>>a;
				al[i].pb(a);
			}
		}
		cin>> m;
		cout<<dpmax(0,0)<<" "<<dpmin(0,0)<<nl;
	}

}