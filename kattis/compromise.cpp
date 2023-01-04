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
		cin >> a>>b;
		vector<string> v(a);
		for (int i=0;i<a;i++){
			cin>> v[i];
		}
		for  (int i=0;i<b;i++){
			ll c=0;
			for (string s:v){
				if (s.at(i)=='1'){
					c++;
				} else {
					c--;
				}
			}
			c>=0 ? cout << '1' : cout<< '0';
		}
		cout<<nl;
	}
}