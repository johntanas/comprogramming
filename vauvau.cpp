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

ll n, m, t, a, b, c, d,k;
string f, s;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >>b >>c >> d;
	for (int i=0;i<3;i++){
		cin>> m;
		m--;
		ll e =m;
		e%=(a+b);
		ll oo=0;
		if (e<a){
			oo++;
		}
		m%=(c+d);
		if (m<c){
			oo++;
		}
		if (oo==2){
			cout<< "both\n";
		}
		if (oo==1){
			cout<<"one"<<nl;
		} 
		if (oo==0){
			cout<<"none"<<nl;
		}
	}

}