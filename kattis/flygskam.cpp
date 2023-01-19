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

double gcDist(double pLa, double pLo, double qLa, double qLo, double r) {
pLa *= M_PI/180; pLo *= M_PI/180; // degree to radian
qLa *= M_PI/180; qLo *= M_PI/180;
return r * acos(cos(pLa)*cos(pLo)*cos(qLa)*cos(qLo) +
cos(pLa)*sin(pLo)*cos(qLa)*sin(qLo) + sin(pLa)*sin(qLa));
}
const double INF=1e9;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;
	ld u,v;
	vector<pair<double,double>> air(n);
	unordered_map<string,int> ma;
	cin>>f>>s;
	ma[f]=0;
	ma[s]=1;
	int pos=2;
	for (int i=0;i<n;i++){
		cin>> f>>u>>v;
		if (!ma.count(f)){
			ma[f]=pos++;
		}
		air[ma[f]]={u,v};
	}
	vector<vector<int>> al;
	al.resize(n,{});
	while (m--){
		cin>>f>>s;
		al[ma[f]].pb(ma[s]);
		al[ma[s]].pb(ma[f]);
	}
	vector<double> visited;
	visited.assign(n,INF);
	visited[0]=0;
	priority_queue<pair<double,int>> pq;
	pq.push({0,0});
	while (!pq.empty()){
		auto mi =pq.top();pq.pop();
		int u=mi.se;
		if (-mi.fi==visited[u]){
			for (int v:al[u]){
				double dif =gcDist(air[v].fi,air[v].se,air[u].fi,air[u].se,6381)+100;
				if (dif +visited[u]<visited[v]){
					visited[v]=dif +visited[u];
					pq.push({-visited[v],v});
				}
			}
		}
	}
	(visited[1] >=INF -1) ? printf("-1") : printf("%.8f",visited[1]);
}	