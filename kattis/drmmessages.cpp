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
	cin >> f;
	ll rot=0;
	for (int i=0;i<f.size()/2;i++){
		rot+=(int) f.at(i)-'A';
	}
	for (int i=0;i<f.size()/2;i++){
		f.at(i)= (f.at(i)-'A'+rot)%26+'A';
	}
	rot=0;
	for (int i=f.size()/2;i<f.size();i++){
		rot+=(int) f.at(i)-'A';
	}
	for (int i=f.size()/2;i<f.size();i++){
		f.at(i)= (f.at(i)-'A'+rot)%26+'A';
	}
	for (int i=0;i<f.size()/2;i++){
		f.at(i)=(f.at(i)-'A'+f.at(i+f.size()/2)-'A')%26+'A';
	}
	cout<<f.substr(0,f.size()/2);
}