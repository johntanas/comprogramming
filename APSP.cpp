#include <bits/stdc++.h>
using namespace std;
int n,m,q;
const int INF = (int) 1e9;
int main(){
    cin >> n >> m>>q;
    while (n){
        int grid[n][n];
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                grid[i][j] = INF;
            }
        }
        int u,v,w;
        for (int i=0;i<=n;i++){
            grid[i][i]=0;
        }
        for (int i=0;i<m;i++){
            cin >> u>>v>>w;
            grid[u][v]=min(grid[u][v],w);
        }
        for (int k=0;k<n;k++){
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    if (grid[i][k] <INF && grid[k][j] <INF){
                        grid[i][j] = min(grid[i][j],grid[i][k]+grid[k][j]);
                    }
                }
            }
        }
        for (int i =0;i<n;i++){
            for (int j=0;j<n;j++){
                for (int k=0;k<n;k++){
                    if (grid[k][k]<0 && grid[i][k] != INF && grid[k][j] !=INF){
                        grid[i][j] = -INF;
                    }
                }
            }
        }
        for (int i=0;i<q;i++){
            cin >> u>>v;
            if (grid[u][v] == -INF){
                cout << "-Infinity" <<endl;
            } else if (grid[u][v] == INF){
                cout << "Impossible" <<endl;
            } else {
                cout << grid[u][v] <<endl;
            }
        }
        cout<<endl;
        cin >> n >> m>>q;
    }
}