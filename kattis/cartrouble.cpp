#include <bits/stdc++.h>
using namespace std;
int t;
unordered_map<int, vector<int> > adjList;
unordered_map<int, vector<int> >  transpose;
unordered_set<int> visited;
vector<int> v;
void dfs(int u){
    for (int vv:adjList[u]){
        if (!visited.count(vv)){
            visited.insert(vv);
            dfs(vv);
        }
    }
}
vector<int> check(){
    vector<int> r ={};
    for (int i:v){
        if (!visited.count(i)){
            r.push_back(i);
        }
    }
    return r;
}
int main(){
    cin >> t;
    for ( int i=0;i<t;i++){
        int id,s,c;
        cin >> id >>s;
        v.push_back(id);
        while (s-->0){
            cin >>c;
            adjList[id].push_back(c);
            transpose[c].push_back(id);
        }
    }
    visited.clear();
    visited.insert(0);
    dfs(0);
    vector<int> unreach = check();
    adjList= transpose;
    visited.clear();
    visited.insert(0);
    dfs(0);
    vector<int> trap = check();
    if (unreach.empty() && trap.empty()){
        cout<< "NO PROBLEMS";
    } else {
        for (int i:trap){
            cout <<"TRAPPED "<< i <<"\n";
        }
        for (int i:unreach){
            cout <<"UNREACHABLE "<< i <<"\n";
        }
    }
}
