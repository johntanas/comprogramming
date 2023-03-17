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
 
ll n, m, t, a, b, k;
void solve(){
	cin >> n>>m;
	ll arr[n];ll arr2[m];
	ll sa=0,sb=0;
	for (int i=0;i<n;i++){
		cin >> arr[i];
		sa+=arr[i];
	}
	for (int i=0;i<m;i++){
		cin >> arr2[i];
		sb+=arr2[i];
	}
	k=0;
	for (int i: arr){
		if (i*n<sa && i*m>sb){
			k++;
		}
	}
	cout << k <<nl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t-->0){
		solve();
	}
}