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
int ext(int a,int b,int &x,int &y){
	int xx =y=0;
	int yy =x=1;
	while (b){
		int q=a/b;
		int t=b;b=a%b;a=t;
		t = xx; xx = x-q*xx; x = t;
		t = yy; yy = y-q*yy; y = t;
	}
	return a;
}
void solve(){
	int a,b,x,y;
	cin>> a >> b >>c;
	int q = ext(a,b,x,y);
	if (c%q){
		cout<<"NO"<<nl;

	} else {
		cout<<"YES"<<nl;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while(n-->0){
		solve();
	}
}