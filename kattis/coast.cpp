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
int pos=2;
int grid[1001][1001];
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
unordered_set<int> lakes={1};
int ff(int i,int j){
	if (grid[i][j]) return 0;
	grid[i][j]=pos;
	int cond =0;
	for (int d=0;d<4;d++){
		int r=i+dr[d];
		int c=j+dc[d];
		if (r<0||c<0||r>=n||c>=m) {cond=1; continue;}
		cond |=ff(r,c);
	}
	return cond;
}
int flood(int i,int j){
	if (grid[i][j]==-1) return 0;
	if (lakes.count(grid[i][j])==0) return 1;
	grid[i][j]=-1;
	int cond =0;
	for (int d=0;d<4;d++){
		int r=i+dr[d];
		int c=j+dc[d];
		if (r<0||c<0||r>=n||c>=m) {cond++; continue;}
		cond +=flood(r,c);
	}
	return cond;
}
char cc;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cin>>cc;
			if (cc=='1'){
				grid[i][j]=1;
			} else{
				grid[i][j]=0;
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (grid[i][j]==0){
				c=ff(i,j);
				if (!c) lakes.insert(pos);
				pos++;
			}
		}
	}
	ll sum=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (grid[i][j]==1){
				sum+=flood(i,j);
			}
		}
	}
	cout<<sum;
}