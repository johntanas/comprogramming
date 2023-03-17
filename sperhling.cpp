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
	cin >> f>>s;
	for (int i=0;i<min(f.size(),s.size());i++){
		if (f.at(i)!=s.at(i)){
			cout<< f.size()-i+s.size()-i;
			return 0;
		}
	}
	cout<< max(f.size(),s.size())-min(f.size(),s.size());
}