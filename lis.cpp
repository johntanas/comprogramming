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
int arr[200];
void print_lis(int i){
	if (p[i]==-1){printf("%d",arr[i]);return;}
	print_lis(p[i]);
	printf(" %d",arr[i]);
}
int main(){
	cin >> m;
	while (m){
		int k=0,end=0;
		vector<int> l(m,0),l_id(m,0);
		p.assign(m,-1);
		for (int i=0;i<m;i++){
			cin>> arr[i];
		}
		for (int i=0;i<m;i++){
			int pos = lower_bound(l.begin(),l.begin()+k,arr[i]) - l.begin();
			l[pos] = arr[i];
			l_id[pos]=i;
			p[i] = pos ? l_id[pos-1] : -1;
			if (pos==k){
				k=pos+1;
				end=i;
			}
			if (pos==k-1){
				end=i;
			}
		}
		cout<< k << " ";
		print_lis(end);
		cout<<nl;
		cin>>m;
	}
}