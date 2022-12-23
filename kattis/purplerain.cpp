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
	int r=0,b=0;
	int sr=0,sb=0,er=0,ssr=0;
	int mr=0;
	for (int i=0;i<f.size();i++){
		if (f.at(i)=='R'){
			r++;
			b--;
			if (r>mr){
				mr=r;
				er=i;
				ssr=sr;
			}
		} else {
			r--;
			b++;
			if (b>mr){
				mr=b;
				er=i;
				ssr=sb;
			}
		}
		if (r<0){r=0;sr=i+1;}
		if (b<0){b=0;sb=i+1;}
	}
	cout << ssr+1<<" "<<er+1;
}