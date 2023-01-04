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
vector<ll> p;
bool memo[360];
void dp(int i){
	for (int j:p){
		int out =(i+j)%360;
		if (!memo[out]){
			memo[out]=true;
			dp(out);
		}
		out =(i-j+360)%360;
		if (!memo[out]){
			memo[out]=true;
			dp(out);
		}
		out =(j-i+360)%360;
		if (!memo[out]){
			memo[out]=true;
			dp(out);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>k;
	p.resize(n);
	memset(memo,false,sizeof memo);
	for (int i=0;i<n;i++){
		cin>> p[i];
	}
	for (int i:p){
		dp(i);
	}
	for (int i=0;i<k;i++){
		cin >> a;
		if (memo[a]){
			cout<< "YES"<<nl;
		} else {
			cout<<"NO"<<nl;
		}
	}
}