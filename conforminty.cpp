#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    unordered_map<long,int> map;
    cin >> n;
    for (int i =0;i<n;i++){
        long cur =0;
        long c;
        vector<int> v;
        for (int j=0;j<5;j++){
            cin>> c;
            v.push_back(c);
        }
        sort(v.begin(),v.end());
        for (int j=0;j<5;j++){
            cur*=100;
            cur+=v.at(j);
        }
        map[cur]++;
    }
    int m=0;
    int cc=0;
    for( auto it = map.begin();it!=map.end();++it){
        if (it->second >m){
            m = it->second;
            cc = m;
        } else if (it->second == m){
            cc +=m;
        }
    }
    cout <<cc;
}