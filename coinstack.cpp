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
	set<pii> ss;
	int b=1;
	while (n-->0){
		cin>>a;
		if (a!=0){
			ss.insert({-a,b});
		}
		b++;
	}
	int ok =1;
	vector<pii> moves;
	while (!ss.empty()){
		auto end= *ss.begin();
		ss.erase(ss.begin());
		if (ss.empty()){
			ok=0;
			break;
		}
		auto end2=*ss.begin();
		ss.erase(ss.begin());
		end.fi++;end2.fi++;
		moves.pb({end.se,end2.se});
		if (end.fi!=0){
			ss.insert(end);
		}
		if (end2.fi!=0){
			ss.insert(end2);
		}
	}
	if (ok){
		cout<<"yes"<<nl;
		for (pii p:moves){
			printf("%d %d\n",p.fi,p.se);
		}
	} else {
		cout<<"no";
	}
}