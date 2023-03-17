#include <bits/stdc++.h>
using namespace std;
int main(){
    string n;
    cin >> n;
    char grid[4][4] ={' '};
    int cur;
    int r=0;
    for (int i =0;i<4;i++){
        cur =(int) n.at(i) -48;
        for (int j =0;j<4;j++){
            if (cur & (8>>j)){
                grid[j][i] = '*';
            } else {
                grid[j][i] = '.';
            }
        }
    }
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            cout << grid[i][j];
            if (j==1){
                cout << ' ';
                cout << ' ';
            }
            if (j!=3){
                cout << ' ';
            }
        }
        cout << endl;
    }
}