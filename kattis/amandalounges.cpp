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
	cin >> n>>m;
	int color[n+1]={0};
	int u,v,w;
	int ok =1;
	vector<vector<int>> al;
	al.resize(n+1,{});
	for (int i=0;i<m;i++){
		cin >> u>>v>>w;
		if (w==2){
			if (color[u]==1 ||color[v]==1){
				ok=0;
			}
			color[u]=color[v]=2;
		} else if (w==0){
			if (color[u]==2 ||color[v]==2){
				ok=0;
			}
			color[u]=color[v]=1;
		} else{
			al[u].pb(v);
			al[v].pb(u);
		}
	}
	queue<int> q;
	for (int i=1;i<=n;i++){
		if (color[i]&&ok){
			q.push(i);
			while (!q.empty()){
				int min = q.front();q.pop();
				for (int j:al[min]){
					if ((color[min]==1 && color[j]==1)||(color[min]==2 && color[j]==2)){
						ok =0;
					} else{
						if (!color[j]){
							q.push(j);
						}
						color[min]==2 ? color[j] =1 : color[j]=2;
					}
				}
			}
		}
	}
	ll out=0;
	for (int i=1;i<=n;i++){
		if (!color[i]&&ok){
			q.push(i);
			color[i]=3;
			a=0;
			b=1;
			while (!q.empty()){
				int min = q.front();q.pop();
				for (int j:al[min]){
					if (color[j]){
						if ((color[min]==3 && color[j]==3)||(color[min]==4 && color[j]==4)){
							ok=0;
						}
						continue;
					}
					if (color[min]==3){
						color[j] =4;
						a++;
					}else{
						color[j]=3;
						b++;
					}
					q.push(j);
				}
			}
			out+=min(a,b);
		}
	}
	if (ok){
		for (int i=1;i<=n;i++){
			if (color[i]==2){
				out++;
			}
		}
		cout << out;
	} else{
		cout<<"impossible";
	}
}