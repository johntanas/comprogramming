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
	cin >> f;
	vector<char> L(f.size(),' ');
	int k=0,lis_end=0;
	for (int i=0;i<f.size();i++){
		int pos = lower_bound(L.begin(),L.begin()+k,f.at(i)) -L.begin();
		L[pos]= f.at(i);
		if (pos==k){
			k=pos+1;
		}
	}
	cout << 26-k;
}