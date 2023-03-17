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
int currentno;
ll n, m, t, a, b;
int dr[] ={1,0,-1,0};
int dc[] ={0,1,0,-1};
int grid[20][20] ={0};
bool visited[20][20] ={false};
int flood(int x,int y){
	int cou =0;
	visited[x][y] =true;
	for (int d=0;d<4;d++){
		int r = x+dr[d];
		int c= y +dc[d];
		if (r<0 || c<0 || r>= n || c>=n){continue;}
		if (grid[r][c] ==currentno && !visited[r][c]){
			cou++;
			cou+=flood(r,c);
		} else if (grid[r][c] ==-1 && !visited[r][c]){
			cou+=flood(r,c);
		}
	}
	return cou;
}
void f(int x,int y){
	if (visited[x][y]){
		return;
	}
	visited[x][y] =true;
	grid[x][y] =-1;
	for (int d=0;d<4;d++){
		int r = x+dr[d];
		int c= y +dc[d];
		if (r<0 || c<0 || r>= n || c>=n){continue;}
		if (grid[r][c] ==currentno || grid[r][c] ==-1){
			f(r,c);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		grid[20][20] ={0};
		char curr;
		int dat[6] ={0};
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cin >> curr;
				grid[i][j] = curr -'1';
			}
		}
		currentno = grid[0][0];
		for (int j=0;j<n;j++){
			for (int k=0;k<n;k++){
				visited[j][k] ={false};
			}
		}
		f(0,0);
		while (true){
			int choose =0;
			int m=0;
			bool cond =true;
			for (int i=0;i<6;i++){
				for (int j=0;j<n;j++){
					for (int k=0;k<n;k++){
						visited[j][k] ={false};
					}
				}
				currentno=i;
				int out =flood(0,0);
				if (out>m){
					choose =i;
					m=out;
					cond =false;
				}
			}
			if (cond){
				break;
			}
			currentno=choose;
			dat[choose]++;
			for (int j=0;j<n;j++){
				for (int k=0;k<n;k++){
					visited[j][k] ={false};
				}
			}
			f(0,0);
		}
		int sum =0;
		cout << accumulate(dat,dat+6,sum) <<nl;
		for (int i : dat){
			cout << i << " ";
		}
		cout <<nl;
	}
}