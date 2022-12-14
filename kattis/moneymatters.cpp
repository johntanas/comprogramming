#include <bits/stdc++.h>
using namespace std;
int weights[10000] ={0};
int cc=0;
unordered_set<int> visited;
vector<vector<int>> adjList;
void dfs(int u){
    for (int v:adjList[u]){
        if (!visited.count(v)){
            visited.insert(v);
            dfs(v);
            cc+= weights[v];
        }
    }
}
int main(){
    int r,c;
    cin >> r>>c;
    for (int i=0;i<r;i++){
        adjList.push_back({});
        cin >> weights[i];
    }
    for (int i=0;i<c;i++){
        int u,v;
        cin >> u >>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int cond =1;
    for (int i =0;i<r;i++){
        if (!visited.count(i)){
            cc+= weights[i];
            visited.insert(i);
            dfs(i);
        }
        if (cc!=0){
            cond = 0;
            break;
        }
    }
    if (cond){
        cout << "POSSIBLE";
    } else {
        cout << "IMPOSSIBLE";
    }
}
