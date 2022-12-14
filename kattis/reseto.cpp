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
	cin >> n >>k;
	bool comp[n+1] ={false};
	for (int i=2;i<=n;i++){
		if (!comp[i]){
			for (int j=i;j<=n;j+=i){
				if (!comp[j]){
					comp[j] =true;
					k--;
					if (k==0){
						cout << j;
						return 0;
					}
				}
			}
		}
	}
}