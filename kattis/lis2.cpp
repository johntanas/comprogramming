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
vector<int> p;
int arr[100000];
void print(int i){
	c++;
	if (p[i]==-1){printf("%d\n%d",c,i);return;}
	print(p[i]);
	printf(" %d",i);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n){
		ll k=0,end=0;
		vector<int> l(n,0),id(n,0);
		p.assign(n,-1);
		for (int i=0;i<n;i++){
			cin>>arr[i];
			int pos =lower_bound(l.begin(),l.begin()+k,arr[i]) -l.begin();
			l[pos] =arr[i];
			id[pos]=i;
			p[i] =pos ?id[pos-1] :-1;
			if (pos==k){
				k=pos+1;
				end=i;
			}
		}
		c=0;
		print(end);
		printf("\n");
	}
}