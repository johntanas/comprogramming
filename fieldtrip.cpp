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
	for (int i=0;i<n;i++){
		cin >> v[i];
	}
	ll sum=accumulate(all(v),0);
	if (sum%3){
		cout << -1;
	} else {
		vector<int> ans;
		int cap =sum/3;
		int out=0;
		for (int i=0;i<n;i++){
			out+=v[i];
			if (out==cap){
				out =0;
				ans.pb(i+1);
			}
			if (out>cap){
				cout <<-1;
				return 0;
			}
		}
		cout << ans[0]<<" "<<ans[1];
	}
}