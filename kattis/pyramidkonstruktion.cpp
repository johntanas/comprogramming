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
	cin >>t>>a>>b;
	for (int i=2;i<=t;i++){
		b-=(i-1)*2;
	}
	c=0;
	if (a&1){
		b+=a/2;
	} else {
		c=1;
		b+=(a)/2;
	}
	if (b<=0){
		cout<<c<<" "<<abs(b);
	} else {
		if (a==0){
			cout<<c<<" "<<0;
		} else {
			cout<<0<<" "<<0;
		}
	}
	
}