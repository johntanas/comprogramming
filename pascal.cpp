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
bitset<100000010> bs;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	a=0;
	bs.set();
	bs[0] =bs[1] =0;
	vector<ll> p;;
	for (ll i =2;i<40000;i++){
		if (bs[i]){
			for (ll j=i*i;j<40000;j+=i){
				bs[j] =0;
			}
			p.push_back(i);
		}
	}
	int l =-1;
	for (int i=0;i<p.size();i++){
		if (p[i]>=t){
			break;
		}
		if (t%p[i] ==0){
			l=i;
			break;
		}
	}
	if (l==-1){
		cout << t-1;
	} else {
		cout << t-t/p[l];
	}
}