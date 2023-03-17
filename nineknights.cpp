#include <bits/stdc++.h>
using namespace std;
char grid[9][9] ={'.'};
bool check(int i,int j){
    if (grid[i+2][j+1] =='k') return true;
    if (grid[i+2][j-1] == 'k') return true;
    if (grid[i-2][j+1] == 'k') return true;
    if (grid[i-2][j-1]=='k') return true;
    if (grid[i+1][j+2]=='k') return true;
    if (grid[i-1][j+2]=='k') return true;
    if (grid[i+1][j-2]=='k') return true;
    if (grid[i-1][j-2] =='k') return true;
    return false;
 }
int main(){
    for (int i=2;i<7;i++){
        for (int j =2;j<7;j++){
            cin >> grid[i][j];
        }
    }
    int ccc =0;
    bool c = true;
    for (int i=2;i<7;i++){
        for (int j =2;j<7;j++){
            if (grid[i][j] =='k'){
                ccc++;
            if(check(i,j)){
                c =false;
                break;
            }
            }
        }
        if (!c){
            break;
        }
    }
    if (c && ccc ==9){
        cout<< "valid";
    } else {
        cout << "invalid";
    }
}