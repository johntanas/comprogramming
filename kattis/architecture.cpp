#include <bits/stdc++.h>
using namespace std;
int main (){
    int r,c;
    cin >> r >> c;
    int dr[r],dc[c];
    for (int i =0;i<r;i++) cin >> dr[i];
    for (int i =0;i<c;i++) cin >> dc[i];
    int grid[r][c];
    for (int i =0; i<r;i++){
        for (int j =0; j<c;j++){
            grid[i][j] = min(dr[i],dc[j]);
        }
    }
    bool cond = true;
    for (int i =0;i<r;i++){
        bool c2 = true;
        for (int j =0;j<c;j++){ if (grid[i][j]==dr[i]){c2 = false;}}
        if (c2) { cond = false;}
    }
    for (int i =0;i<c;i++){
        bool c2 = true;
        for (int j =0; j<r;j++){if (grid[j][i] == dc[i]){c2 = false;}}
        if (c2) { cond = false;}
    }
    cout << (cond ? "possible" : "impossible") <<endl;
}