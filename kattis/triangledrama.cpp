#include <bits/stdc++.h>
using namespace std;
int main(){
    int r,c;
    cin >> r;
    int grid[r][r];
    for (int i=0;i<r;i++){
        for(int j=0;j<r;j++){
            cin >> grid[i][j];
        }
    }
    int m=-1;
    int oa,ob,oc;
    for (int a=0;a<r;a++){
        for (int b=a+1;b<r;b++){
            for(int c=b+1;c<r;c++){
                if (grid[a][b]*grid[b][c]*grid[c][a]>m){
                    oa=a+1,ob=b+1,oc=c+1;
                    m=grid[a][b]*grid[b][c]*grid[c][a];
                }
            }
        }
    }
    cout << oa <<" "<< ob <<" "<< oc;
}
