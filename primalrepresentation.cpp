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
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<ll> p;
	bitset<100010> bs;
	bs.set();
	bs[0] =bs[1]=0;
	for (ll i=2;i<100000;i++){
		if (bs[i]){
			for (ll j=i*i;j<100000;j+=i){
				bs[j] =0;
			}
			p.pb(i);
		}
	}
	cin >> n;
	while (!cin.eof()){
		if (n<0){
			cout <<"-1" <<" ";
			n*=-1;
		}
		for (int i=0;i<p.size();i++){
			int pow=0;
			while (n%p[i]==0){
				n/=p[i];
				pow++;
			}
			if (pow){
				cout << p[i];
				if (pow>1){
					cout << "^"<< pow;
				}
				cout <<" ";
			}
		}
		if (n!=1){
			cout << n;
		}
		cout << nl;
		cin >> n;
	}
}