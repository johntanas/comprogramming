#include<bits/stdc++.h>
using namespace std;
int dr[] ={1,0,-1,0};
int dc[] ={0,1,0,-1};
int ddr[] ={1,0,-1,0,1,1,-1,-1};
int ddc[] ={0,1,0,-1,1,-1,1,-1};
int r,c;
int grid[4][4];
void floodfill(int sr,int sc){
    if (grid[sr][sc] ==1){
        grid[sr][sc] =2;
    }else {
        return;
    }
    for (int d=0;d<4;d++){
        int rr = sr + dr[d];
        int cc = sc +dc[d];
        if (rr<0 || cc<0 || rr>=r || cc >=c){continue;};
        floodfill(rr,cc);
    }
}
bool ff(int sr,int sc){
    if (grid[sr][sc] !=0){return false;}
    bool cond = false;
    grid[sr][sc] =2;
    for (int d=0;d<8;d++){
        int rr = sr + ddr[d];
        int cc = sc +ddc[d];
        if (rr<0 || cc<0 || rr>=r || cc >=c){cond =true; continue;}
        if (ff(rr,cc)){
            cond = true;
        }
    }
    return cond;
}
int main(){
    cin >> r >> c;
    int mask =(1<<r*c) -1;
    int count =0;
    for (int subset = mask; subset; subset = (mask & (subset-1))){
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                if (subset & (1<<(i*c+j))){
                    grid[i][j] = 1;
                } else {
                    grid[i][j] =0;
                }
            }
        }
        bool cc = true;
        bool cond =true;
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                if (grid[i][j] ==1){
                    if (cond){
                        floodfill(i,j);
                        cond =false;
                    } else {
                        cc =false;
                    }
                } else if (grid[i][j]==0){
                    if (!ff(i,j)){
                        cc =false;
                    }
                }
            }
        }
        if (cc){count++;}
    }
    cout << count;
}