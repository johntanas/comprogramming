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
int grid[1001][1001];
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
int pos=2;
int pos2=-2;
void flood(int x,int y,int t){
	if (grid[x][y] !=t) return;
	if (t){
		grid[x][y]=pos;
	} else{
		grid[x][y]=pos2;
	}
	for (int d=0;d<4;d++){
		int r=x+dr[d];
		int c=y+dc[d];
		if (r<0||c<0||r>=n||c>=m) continue;
		flood(r,c,t);
	}
}
char cc;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cin>> cc;
			if (cc =='1'){
				grid[i][j]=1;
			} else{
				grid[i][j]=0;
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (grid[i][j]==1){
				flood(i,j,1);
				pos++;
			} else if(grid[i][j]==0){
				flood(i,j,0);
				pos2--;
			}
		}
	}
	int q;
	cin>>q;
	while(q-->0){
		cin >> a>>b>>c>>k;
		a--;
		b--;
		c--;
		k--;
		if (grid[a][b]==grid[c][k]){
			grid[a][b]<0 ? cout<< "binary" <<nl : cout<<"decimal"<<nl;
		} else{
			cout<<"neither"<<nl;
		}
	}
}