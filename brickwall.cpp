#include <bits/stdc++.h>
//-D_GLIBCXX_DEBUG -fsanitize=undefined
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
int visited[301][301][301];
vector<int> row;
int ok =0;
void dp(int i,int j,int k,int pos,int add){
	if (pos==n ||ok){
		ok|=(!add);
		return;
	}
	if ((i||j||k)&&(!add)){
		return;
	}
	if (visited[i][j][k]){return;}
	if (i<a){
		int dif = add+1;
		if (dif>=row[pos]){
			dp(i+1,j,k,pos+1,dif-row[pos]);
		} else {
			dp(i+1,j,k,pos,dif);
		}
	}
	if (j<b){
		int dif = add+2;
		if (dif>=row[pos]){
			if (pos+1<n &&dif-row[pos]>=row[pos+1]){
				dp(i,j+1,k,pos+2,dif-row[pos]-row[pos+1]);
			} else {
				dp(i,j+1,k,pos+1,dif-row[pos]);
			}
		} else {
			dp(i,j+1,k,pos,dif);
		}
	}
	if (k<c){
		int dif = add+3;
		if (pos+2<n &&dif-row[pos]>=row[pos+1]+row[pos+2]){
			dp(i,j,k+1,pos+3,dif-row[pos]-row[pos+1]-row[pos+2]);
		} else if (pos+1<n &&dif-row[pos]>=row[pos+1]){
			dp(i,j,k+1,pos+2,dif-row[pos]-row[pos+1]);
		} else {
			dp(i,j,k+1,pos+1,dif-row[pos]);
		}
	}
	visited[i][j][k]=1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>a>>b>>c;
	memset(visited,0,sizeof visited);
	row.resize(n);
	for (int &i:row){
		cin>>i;
	}
	dp(0,0,0,0,0);
	printf("%s",(ok)?"YES":"NO");
}