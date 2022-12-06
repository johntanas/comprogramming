#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for (int i =1;i<=t;i++){
        int g,c;
        cout << "Case #" <<i <<": ";
        cin >> g;
        unordered_map<int,int> set;
        for (int j=0;j<g;j++){
            cin >> c;
            set[c]++;
        }
        for (auto it = set.begin();it !=set.end();++it){
            if (it->second !=2){cout << it->first <<endl;}
        }
    }
}