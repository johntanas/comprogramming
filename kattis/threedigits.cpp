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
	cin >> n;
	ll out=1;
	ll twos=0,fives=0;
	for (ll i=1;i<=n;i++){
		ll e=i;
		while (e%10==0){
			e/=10;
		}
		out*=e;
		while (out%5==0){
			out/=5;
			fives++;
		}
		while (out%2==0){
			out/=2;
			twos++;
		}
		out%=100000;
	}
	twos-=fives;
	while (twos--){
		out*=2;
		out%=1000;
	}
	if(n > 6 && out < 100) {
        cout << "0";
        if(out < 10) {
            cout << "0";
        }
    }
	cout<<out%1000;
}