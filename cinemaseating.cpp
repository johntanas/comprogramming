#include <bits/stdc++.h>
using namespace std;
int main(){
    int r,c,n,a,b;
    cin >> r>> c >>n;
    int dat[9] ={0};
    int grid[r][c]={0};
    for (int i=0;i<n;i++){
        cin >> a>>b;
        grid[a-1][b-1] =1;
    }
    int dr[] ={1,0,-1,0,1,1,-1,-1};
    int dc[]={0,1,0,-1,1,-1,1,-1};
    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if (grid[i][j]){
                int e=0;
                for (int d=0;d<8;d++){
                    a = dr[d] +i;
                    b =dc[d] +j;
                    if (a<0 || b<0|| a>=r||b>=c){
                        continue;
                    }
                    if (grid[a][b]){
                        e++;
                    }
                }
                dat[e]++;
            }
        }
    }
    for (int i:dat){
        cout << i <<" ";
    }
    cout<<endl;
}
