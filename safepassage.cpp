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
	vector<int> v(n);
	for (int &i:v){
		cin>>i;
	}
	sort(all(v));
	c=0;
	a=v[0];
	b=v[1];
	while (n>3){
		ll A = a+2*b+v[n-1];
		ll B= 2*a+v[n-1]+v[n-2];
		c+= A<B ? A:B;
		n-=2;
	}
	if (n==3){
		c+=v[2]+a+b;
	} else {
		c+=b;
	}
	cout<<c;
}