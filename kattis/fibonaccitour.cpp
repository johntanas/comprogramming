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
vector<vector<int>> al;
vector<ll> man;
vector<int> no;
int memo[100001][100];
int dp(int i,int pos){
	int &ans = memo[i][pos];
	if (ans !=-1) return ans;
	ans =0;
	if (pos==0){
		for (int u:al[i]){
			if (no[u]==0){
				ans=max(dp(u,1),ans);
			}
			if (no[u]==2){
				ans=max(dp(u,2),ans);
			}
		}
	} else {
		for (int u:al[i]){
			if (no[u]==pos+1){
				ans=max(dp(u,pos+1),ans);
			}
		}
	}
	ans++;
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;
	vector<ll> fib ={1,1};
	man.resize(n);
	for (int i=0;i<n;i++){
		cin>>man[i];
	}
	memset(memo,-1,sizeof memo);
	a=*max_element(all(man));
	while (fib[fib.size()-1]<=a){
		fib.pb(fib[fib.size()-1]+fib[fib.size()-2]);
	}
	al.resize(n,{});
	for (int i=0;i<m;i++){
		int u,v;
		cin >> u>>v;
		al[u-1].pb(v-1);
		al[v-1].pb(u-1);
	}
	no.resize(n);
	for (int i=0;i<n;i++){
		int pos = lower_bound(all(fib),man[i])-fib.begin();
		if (fib[pos]!=man[i]){
			no[i]=-1;
		} else {
			no[i]=pos;
		}
	}
	int best=0;
	for (int i=0;i<n;i++){
		if (no[i]!=-1 && memo[i][no[i]]==-1){
			best=max(dp(i,no[i]),best);
		}
	}
	cout<< best;
}