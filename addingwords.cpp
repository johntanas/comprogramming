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
	while (true){
		if (cin.eof()){
			break;
		}
		unordered_map<string,int> ma;
		unordered_map<int,string> maint;
		unordered_set<string> seen;
		while (cin>>f && f!="clear"){
			if (f=="def"){
				cin >> f >> a;
				if (seen.count(f)){
					maint[ma[f]]="";
				}
				ma[f]=a;
				maint[a]=f;
				seen.insert(f);
			} else {
				ll out=0;
				int plus=1;
				int ok =1;
				while (cin >>f && cin>>s){
					cout<< f <<" "<< s<<" ";
					if (!seen.count(f)){
						ok=0;
					}
					if (plus){
						out+=ma[f];
					} else {
						out-=ma[f];
					}
					if (s=="-"){
						plus=0;
					} else if (s=="="){
						break;
					} else {
						plus=1;
					}
				}
				if (maint[out]!=""&&ok){
					cout<< maint[out]<<nl;
				} else {
					cout<<"unknown"<<nl;
				}
			}
		}
	}
}