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
	cin >> n;
	const int maxn= 2e5+1;
	int pre[maxn]={0};
	int suf[maxn]={0};
	for (int i=0;i<n;i++){
		cin>>a;
		pre[a]+=a;
		suf[a]+=a;
	}
	for (int i=1;i<maxn;i++){
		pre[i]+=pre[i-1];
	}
	for (int i=maxn-1;i>=1;i--){
		suf[i-1]+=suf[i];
	}
	for (int i=1;i<maxn;i++){
		if (pre[i-1]==suf[i+1]){
			cout<<i;
			return 0;
		}
	}
}