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
void solve(){
	for (int i=0;i<f.size();i++){
		if (f.at(i)== 'a'||f.at(i)== 'e'||f.at(i)== 'i'||f.at(i)== 'o'||f.at(i)== 'u'){
			cout<< f.at(i);
			i+=2;
		} else{
			cout<< f.at(i);
		}
	}
	cout<<" ";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin>>f){
		solve();
	}
}