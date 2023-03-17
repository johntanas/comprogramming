#include <bits/stdc++.h>
using namespace std;
using pii =pair<long,long>;
int main(){
    int f,b;
    cin >> f >>b;
    vector<int> v(f);
    vector<int> vv(b);
    for (int i=0;i<f;i++){
        cin >> v[i];
    }
    for(int i=0;i<b;i++){
        cin>>vv[i];
    }
    vector<pii> ps;
    for (int i:v){
        for (int j:vv){
            ps.push_back(pii(i,j));
        }
    }
    sort(ps.begin(),ps.end(),[](pii a,pii b){return (a.first*b.second == a.second*b.first)? a.first <b.first : a.first*b.second <a.second*b.first;});
    for (pii p:ps){
        cout << "("<<p.first << ","<<p.second<<")\n";
    }
}
