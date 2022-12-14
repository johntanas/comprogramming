#include <bits/stdc++.h>
using namespace std;
using tii = tuple<int,int,int>;
int grid[10001][10001] ={0};
int o,g,r,c;
int main(){
    cin >> g;
    o =g;
    int x,y;
    while (g-->0){
        cin >> r>>c;
        grid[r][c]++;
    }
    cin >>g;
    while (g-->0){
        cin >> x >> y >>r;
        for (int i=max(x-r,0);i<=min(x+r,10000);i++){
            for (int j=max(y-r,0);j<=min(y+r,10000);j++){
                if (grid[i][j]>0 && x*x +j*j -2*x*i + i*i -2*y*j +y*y<=r*r){
                    o-= grid[i][j];
                    grid[i][j]=0;
                }
            }
        }
    }
    cout << o;
}
