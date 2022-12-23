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
bitset<1000010> bs;
vector<ll> p;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	bs.set();
	bs[0]=bs[1]=0;
	for (ll i =0;i<50000;i++){
		if(bs[i]){
			for(ll j=i*i;j<50000;j+=i){
				bs[j]=0;
			}
			p.pb(i);
		}
	}
	cin >> n;
	a=0;
	for (ll i:p){
		while (n%i==0){
			a+=1;
			n/=i;
		}
	}
	if (n!=1){
		cout << a+1<<nl;
	} else {
		cout << a<<nl;
	}
}