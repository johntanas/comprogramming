#include <bits/stdc++.h>
using namespace std;
using pis = pair<int,string>;
int a,b,n,m,l;
int solve(){
    int cost = (n-m)*a;
    int aa = n;
    int out =0;
    while (true){
        aa /=2;
        out +=b;
        if (aa< m){
            break;
        }
        cost = min(cost,out+(aa-m)*a);
        if (aa ==m){
            break;
        }
    }
    return cost;
}
int main(){
    int t,curr;
    string s;
    char _;
    cin >> t;
    for (int i=1;i<=t;i++){
        cout << "Case "<<i;
        cin >> n>>m>>l;
        vector<pis> v;
        while (l-->0){
            getline(cin,s,':');
            cin >> a >>_ >> b;
            curr =solve();
            v.push_back(pis(curr,s));
        }
        sort(v.begin(),v.end());
        for (pis p:v){
            cout  << p.second << " " << p.first;
        }
        cout << "\n";
    }   
}
