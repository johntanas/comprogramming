#include <bits/stdc++.h>

using namespace std;
int main(){
    int r,c;
    cin >> r >> c;
    char grid[r][c];
    for (int i =0;i<r;i++){
        for (int j=0;j<c;j++){
            cin >> grid[i][j];
        }
    }
    int cc;
    for (int j=0;j<c;j++){
        cc=0;
        for (int i=0;i<r;i++){
            if (grid[i][j] =='a'){
                cc++;
                grid[i][j] = '.';
            } 
            if (grid[i][j] == '#'){
                int k =i;
                while (cc>0){
                    k--;
                    grid[k][j] = 'a';
                    cc--;
                }
            }
        }
        int k =r-1;
        while (cc>0){
            grid[k][j] = 'a';
            k--;
            cc--;
        }
    }
    for (int i =0;i<r;i++){
        for (int j=0;j<c;j++){
            cout << grid[i][j];
        }
        cout <<endl;
    }
}