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
	vector<ll> v(n);
	for(int i=0;i<n;i++){
		cin >>a>>b;
		a--;b--;
		v[b]=a;
	}
	c=0;
	for (int i=0;i<n;i++){
		c=max(c+1,v[i]+1);
	}
	cout<<c-n;
}