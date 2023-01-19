#include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1749/E
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
vector<vector<int>> grid;
const int INF =1e9;
int dr[]={1,0,-1,0,1,1,-1,-1};
int dc[] ={0,1,0,-1,1,-1,1,-1};
void solve(){
	char cc;
	grid.clear();
	grid.resize(n,vector<int>(m));
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cin>>cc;
			if (cc=='@'){
				grid[i][j]=INF;
			} else if (cc=='.'){
				grid[i][j]=1;
			} else {
				grid[i][j]=0;
			}
		}
	}
	vector<vector<int>> visited;
	visited.assign(n,vector<int>(m,INF));
	priority_queue<pair<int,pii>> pq;
	for (int i=0;i<n;i++){
		visited[i][0]=grid[i][0];
		if (visited[i][0]!=INF){
			pq.push({-visited[i][0],{i,0}});
		}
	}
	for (int i=0;i<m;i++){
		visited[n-1][i]=grid[n-1][i];
		if (visited[n-1][i]!=INF){
			pq.push({-visited[n-1][i],{n-1,i}});
		}
	}
	while (!pq.empty()){
		auto mi = pq.top();pq.pop();
		int i=mi.se.fi,j=mi.se.se;
		if (-mi.fi==visited[i][j]){
			for (int d=0;d<8;d++){
				int r = i+dr[d];
				int c=j+dc[d];
				if (r<0||c<0||r>=n||c>=m||grid[r][c]==INF){continue;}
				if (visited[i][j]+grid[r][c]<visited[r][c]){
					visited[r][c]=visited[i][j]+grid[r][c];
					pq.push({-visited[r][c],{r,c}});
				}
			}
		}
	}
	int ma = INF;
	for (int i=0;i<m;i++){
		ma=min(ma,visited[0][i]);
	}
	for (int i=0;i<n;i++){
		ma=min(ma,visited[i][m-1]);
	}
	if(ma==INF){
		cout<<-1 <<nl;
	} else {
		cout<< ma<<nl;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n>>m&&n){
		solve();
	}
}