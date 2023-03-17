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
#define LSOne(S) ((S)& -(S))
typedef vector<ll> vi;
ll n, m, t, a, b, c, k;
string f, s;
class FenwickTree {
public:
	vi ft;
	FenwickTree(int m) {ft.assign(m+1,0);}
	ll rsq(int j){
		ll sum=0;
		for (;j;j-=LSOne(j))
			sum+=ft[j];
		return sum;
	}
	ll rsq(int i, int j){return rsq(j)-rsq(i-1);}
	void update(int i,ll v){
		for (;i<ft.size();i+=LSOne(i)){
			ft[i]+=v;
		}
	}
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;
	vector<ll> values(6);
	for (int i=0;i<6;i++){
		cin>>values[i];
	}
	vector<FenwickTree> v;
	v.assign(6,FenwickTree(n));
	cin>>f;
	vector<int> types(n);
	for (int i=0;i<n;i++){
		int pos =f.at(i)-'1';
		types[i]=pos;
		v[pos].update(i+1,1);
	}
	while (m--){
		cin >> a >>b >>c;
		if (a==1){
			c--;
			v[types[b-1]].update(b,-1);
			types[b-1]=c;
			v[c].update(b,1);
		}
		if (a==2){
			b--;
			values[b]=c;
		}
		if (a==3){
			ll sum=0;
			for (int i=0;i<6;i++){
				sum+=v[i].rsq(b,c)*values[i];
			}
			cout<<sum<<nl;
		}
	}
}