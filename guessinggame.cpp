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
	cin>>n;
	while (n){
		ll low =0,high=11;
		cin>>f>>s;
		while (true){
			if (f=="right"){
				break;
			}
			if (s=="low"){
				low=max(low,n);
			} else {
				high = min(high,n);
			}
			cin>>n>>f>>s;
		}
		if (low<n&&n<high){
			cout<<"Stan may be honest"<<nl;
		} else {
			cout<<"Stan is dishonest"<<nl;
		}
		cin>>n;
	}
}