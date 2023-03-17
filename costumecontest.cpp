#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >>n;
    map<string,int> map;
    string name;
    while (n-->0){
        cin >> name;
        map[name]++;
    }
    int m =9999;
    vector<string> names;
    for (auto it =map.begin();it!=map.end();it++){
        if (it->second<m){
            names.clear();
            names.push_back(it->first);
            m=it->second;
        } else if (it->second == m){
            names.push_back(it->first);
        }
    }
    for (string ss:names){
        cout << ss << endl;
    }
}