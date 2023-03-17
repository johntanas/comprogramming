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
	while (cin >> n>>f){
		for (int i=0;i<f.size();i++){
			int out;
			if (f.at(i)=='.'){
				out = (27+n)%28;
			} else if (f.at(i)=='_'){
				out = (26+n)%28;	
			} else{
				out = (f.at(i)-'A'+n)%28;
			}
			if (out ==27){
				f.at(i)='.';
			} else if (out ==26){
				f.at(i)='_';
			} else{
				f.at(i)='A'+out;
			}
		}
		reverse(all(f));
		cout<<f<<nl;
	}
}