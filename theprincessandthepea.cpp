#include <bits/stdc++.h>
// 73 partial score, maybe some optimisation to do with no of nights?
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
	int mm,n,c;
	cin >> mm>>n>>c;
	int l =0,r=mm;
	while ((r-l)>max((c*2-2),n+1)){
		int m =l+(r-l)/2;
		cout<<"? ";
		for (int i=l;i<m;i++){
			cout<<i<<" ";
		}
		cout<<endl;
		int ok;
		cin>>ok;
		if (ok){
			r=m;
		} else {
			l=m;
		}
		if (ok){
			n-=c;
		}
		n--;
	}
	while (true){
		if (r-l<n+2){
			break;
		}
		cout<<"? ";
		for (int i=0;i<n-c;i++){
			cout<<l+i<<" ";
		}
		cout<<endl;
		int ok;
		cin>>ok;
		if (ok){
			n-=c;
			r=l+n;
		} else {
			l+=n-c;
		}
		n--;
	}
	for (int i=l;i<r-1;i++){
		int ok;
		cout<<"? "<<i<<endl;
		cin>>ok;
		if (ok){
			cout<<"! "<<i<<endl;
			return 0;
		}
		n--;
	}
	cout<<"! "<<r-1<<endl;
}