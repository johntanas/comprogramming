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
ll mod(ll a, ll m) {
	return ((a%m) + m) % m;
}
int ext(int a,int b , int &x,int &y){
	int xx =y =0;
	int yy=x=1;
	while (b){
		int q=a/b;
		int t=b;b=a%b;a=t;
		t=xx;xx=x-q*xx;x=t;
		t=yy;yy=y-q*yy;y=t;
	}
	return a;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> m && cin>> n && m){
		for (int i=0;i<n;i++){
			char cc;
			cin >> a >> cc >> b;
			if (cc=='-'){
				cout<< mod(a-b,m);
			}
			if (cc=='+'){
				cout<< mod(a+b,m);
			}
			if (cc=='/'){
				int x,y;
				int d = ext(b,m,x,y);
				if (d!=1){
					cout << -1;
				} else {
					cout<<mod(a*x,m);
				}
			}
			if (cc=='*'){
				cout<< mod(a*b,m);
			}
			cout<<nl;
		}
	}
}