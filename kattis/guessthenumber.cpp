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
	int l=1,r=1000;
	while (r-l>1){
		int m=l+(r-l)/2;
		cout<<m<<endl;
		cin>> s;
		if (s=="correct"){
			return 0;
		} else if (s=="higher"){
			l=m+1;
		} else {
			r=m-1;
		}
	}
	cout<<r<<endl;
	cin>> s;
	if (s!="correct"){
		cout<<l<<endl;
	}
}