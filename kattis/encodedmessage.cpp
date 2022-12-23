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
void solve(){
	cin>>f;
	m=sqrt(f.size());
	char grid[m][m];
	a=0;
	for (int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			grid[i][j]=f.at(a++);
		}
	}
	for (int j=m-1;j>=0;j--){
		for(int i=0;i<m;i++){
			cout<<grid[i][j];	
		}
	}
	cout<<nl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while(n-->0){
		solve();
	}
}