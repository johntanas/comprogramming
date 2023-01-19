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
	while (cin>> n>>a>>b>>c && (n||a||b||c)){
		ll out=1080;
		if (a>n){
			out+=9*(40-a+n);
		} else{
			out+=9*(n-a);
		}
		if (a>b){
			out+=9*(40-a+b);
		} else{
			out+=9*(b-a);
		}
		if (c>b){
			out+=(40-c+b)*9;
		} else {
			out+=9*(b-c);
		}
		cout<<out<<nl;
	}
}