#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,p,m;
    cin >> n >> p  >>m;
    unordered_map<string,int> map;
    unordered_set<string> set;
    string name;
    while (n-->0){
        cin>> name;
    }
    int c;
    for (int i =0;i<m;i++){
        cin>>name >> c;
        map[name] += c;
        if (map.find(name)->second >=p && !set.count(name)){
            set.insert(name);
            cout << name << " wins!\n";
        }
    }
    if (set.size() ==0){
        cout << "No winner!";
    }
}