#include <bits/stdc++.h>
//-D_GLIBCXX_DEBUG
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
const ll INF=1e10;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	unordered_map<int,vector<ll>> planets;
	vector<set<pii>> cords(3);
	cords.assign(3,{});
	for (int i=0;i<n;i++){
		cin>> a>>b>>c;
		planets.insert({i,{a,b,c}});
		cords[0].insert({a,i});
		cords[1].insert({b,i});
		cords[2].insert({c,i});
	}
	ll out=0;
	vector<vector<pii>> al;
	al.resize(n,{});
	for (auto [key,v]:planets){
		for (int i=0;i<3;i++){
			auto point = cords[i].lower_bound({v[i],k});
			if (point !=cords[i].begin()){
				--point;
			}
			if (point !=cords[i].begin()){
				auto [k,val] = *point;
				ll currprice=v[i]-k;
				al[key].pb({currprice,val});
				al[val].pb({currprice,key});
			}
			point = cords[i].lower_bound({v[i],k});
			if (point !=cords[i].end()){
				++point;
			}
			if (point !=cords[i].end()){
				auto [k,val] = *point;
				ll currprice=k-v[i];
				al[key].pb({currprice,val});
				al[val].pb({currprice,key});
			}
		}
	}
	vector<int> visited;
	visited.assign(n,1);
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,0});
	while (!pq.empty()){
		auto mi = pq.top();pq.pop();
		if (visited[mi.se]){
			visited[mi.se]=0;
			out+=mi.fi;
			for (auto p:al[mi.se]){
				pq.push(p);
			}
		}
	}
	cout<<out;
}