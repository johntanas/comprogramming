#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int grid[n][n];
    char c;
    for (int i =0;i<n;i++){
        for (int j =0;j<n;j++){
            cin >> c;
            (c == 'W') ? grid[i][j] =-1 : grid[i][j] =1;
        }
    }
    bool cond = true;
    for (int i =0;i<n;i++){
        int sum = 0;
        int p =0;
        int pp =0;
        for (int j=0;j<n;j++){
            sum+=grid[i][j];
            if (grid[i][j] == p){
                pp++;
                if (pp ==3){
                    cond = false;
                }
            } else {
                p = grid[i][j];
                pp =1;
            }
        }
        if (sum!=0){
            cond =false;
        }
    }
    for (int j =0;j<n;j++){
        int sum =0;
        int p =0;
        int pp =0;
        for (int i=0;i<n;i++){
            sum+=grid[i][j];
            if (grid[i][j] == p){
                pp++;
                if (pp ==3){
                    cond = false;
                }
            } else {
                p = grid[i][j];
                pp =1;
            }
        }
        if (sum!=0){
            cond =false;
        }
    }
    if (cond){
        cout << 1;
    } else {
        cout <<0;
    }
}