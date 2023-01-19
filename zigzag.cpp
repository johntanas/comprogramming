#include <bits/stdc++.h>
// I did this beforehand, but I looked at someone else solution >.>
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
	if (n<=25){
		cout<<"a"<<(char)('a'+n);
		return 0;
	}
	string s="a";
	if (n%25==0){
		int ok=0;
		while (n>=25){
			n-=25;
			if (ok){
				s.pb('a');
			} else {
				s.pb('z');
			}
			ok^=1;
		}
		cout<<s;
		return 0;
	}
	int r=n%25;
	bool see = r&1;
	s+= 'n' +r/2;
	int ok=1;
	while (n>=25){
		n-=25;
		if (ok){
			s.pb('a');
		} else {
			s.pb('z');
		}
		ok^=1;
	}
	if (!see){
		if (s[s.size()-1]=='a'){
			s[s.size()-1]++;
		} else {
			s[s.size()-1]--;
		}
	}
	cout<<s;
}