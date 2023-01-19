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
int memo[100];
int grid[50][50];
int dr[] ={1,0,-1,0};
int dc[] ={0,1,0,-1};
int visited[100][50][50];
int flood(int i,int j,int mi,int ma){
	visited[mi][i][j]=1;
	int out=1;
	for (int d=0;d<4;d++){
		int r=i+dr[d];
		int c=j+dc[d];
		if (r<0||c<0||r>=n||c>=m){continue;}
		if (grid[r][c]>=mi &&grid[r][c]<=ma&&!visited[mi][r][c]){out+=flood(r,c,mi,ma);}
	}
	return out;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;
	memset(memo,-1,sizeof memo);
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cin>>grid[i][j];
		}
	}
	memo[99]=n*m;
	for (int k=0;k<99;k++){
		memset(visited,0,sizeof visited);
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				if (!visited[grid[i][j]][i][j]){
					int out = flood(i,j,grid[i][j],grid[i][j]+k);
					memo[k]=max(memo[k],out);
				}
			}
		}
	}
	cin>> a;
	while (a-->0){
		cin>> b;
		for (int i=0;i<100;i++){
			if (memo[i]>=b){
				cout<<i<<nl;
				break;
			}
		}
	}
}