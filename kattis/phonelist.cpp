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
	while (n-->0){
		cin>>m;
		vector<string> v(m);
		while (m-->0){
			cin>>v[m];	
		}
		int ok=1;
		sort(all(v));
		s="-1";
		for (string f:v){
			if (f.find(s)==0){
				ok=0;
				break;
			}
			s=f;
		}
		if (ok){
			cout<<"YES"<<nl;
		} else{
			cout<<"NO"<<nl;
		}
	}
}