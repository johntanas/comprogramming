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
vector<int> v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;
	v.resize(n);
	for (int &i:v){
		cin>>i;
	}
	vector<ll> pre(n);
	for (int i=0;i<n;i++){
		if (i){
			pre[i]=pre[i-1]+v[i];
		} else {
			pre[i]=v[i];
		}
	}
	while(m-->0){
		cin>>a;
		int curr=0;
		for (int i=n-1;i>=0;i--){
			int pos =lower_bound(pre.begin(),pre.begin()+i,(a-curr))-pre.begin();
			if (pos==i+1){
				break;
			}
			if (pre[pos]==a-curr || a-curr==0){
				cout<<"Yes"<<nl;
				goto cont;
			}
			curr+=v[i];
		}
		cout<<"No"<<nl;
		cont:
		continue;
	}
}