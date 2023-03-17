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
ll memo[1002][1002]={0};
int grid[1000][1000]={0};
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
const ll mod = (1<<31) -1;
void flood(int i,int j){
	if (grid[i][j] !=1){
		return;
	}
	grid[i][j]=2;
	for (int d=0;d<4;d++){
		int r=i+dr[d];
		int c = j +dc[d];
		if (r<0||c<0||r>=n||c>=n){continue;}
		flood(r,c);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	memo[0][0]=1;
	char cc;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin>>cc;
			if (cc=='.'){
				grid[i][j]=1;
			} else{
				grid[i][j]=0;
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (grid[j][i]){
				if (j>0){
					memo[j][i]+=memo[j-1][i] % mod;
				}
				if (i>0){
					memo[j][i]+=memo[j][i-1]% mod;
				}
			}
		}
	}
	flood(0,0);
	if (memo[n-1][n-1]){
		cout<<memo[n-1][n-1]%mod;
	} else {
		if (grid[n-1][n-1]==2){
			cout<<"THE GAME IS A LIE";
		} else {
			cout<<"INCONCEIVABLE";
		}
	}
}