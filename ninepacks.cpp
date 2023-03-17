#include <bits/stdc++.h>
 // DAG didnt work?
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
	int inf =1<<29;
	vector<int> memo(100002,inf);
	vector<int> memo2(100002,inf);
	cin.tie(0);
	cin >> n;
	memo[0]=memo2[0]=0;
	int best=inf;
	for (int i=0;i<n;i++){
		cin>>a;
		for (int j=memo.size()-a-1;j>=0;j--){
			if (memo[j]<memo[j+a]){
				memo[j+a]=memo[j]+1;
			}
		}
	}
	cin>> m;
	for (int i=0;i<m;i++){
		cin>>a;
		for (int j=memo.size()-a-1;j>=0;j--){
			if (memo2[j]<memo2[j+a]){
				memo2[j+a]=memo2[j]+1;
			}
		}
	}
	for (int i=1;i<memo.size();i++){
		if(memo[i]+memo2[i]<best){
			best=memo[i]+memo2[i];
		}
	}
	if (best<inf/2){
		cout<<best;
	} else{
		cout<<"impossible";
	}
}