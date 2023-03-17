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
	cin >> n;
	while (n!=4){
		int count =1;
		while (true){
			vector<int> out;
			for (int i=2;i<=sqrt(n);i++){
				while (n%i==0){
					out.pb(i);
					n/=i;
				}
			}
			if (n>1){
				out.pb(n);
			}
			if (out.size()==1){
				n=out[0];
				break;
			}
			n=0;
			for (auto i:out){
				n+=i;
			}
			count++;
		}
		cout << n << " "<<count <<nl;
		cin >> n;
	}
}