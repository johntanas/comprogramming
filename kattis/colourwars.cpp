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
char cc;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	unordered_map<int,int> ma;
	cin >> n;
	a=0;
	for (int i=0;i<n;i++){
		cin>>b;
		ma[b]++;
		if (ma[b]==b+1){
			a+=b+1;
			ma[b]=0;
		}
	}
	for (auto [k,v]:ma){
		if (v!=0)a+=k+1;
	}
	cout<<a;
}