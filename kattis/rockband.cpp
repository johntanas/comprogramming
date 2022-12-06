#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,s;
    cin >> m >>s;
    int start[m] = {0};
    int grid[m][s];
    unordered_set<int> ss;
    for (int i =0;i<m;i++){
        for (int j=0;j<s;j++){cin>>grid[i][j];}
    }
    bool cond;
    ss.insert(grid[0][0]);
    while (true){
        cond =true;
        for (int i =0;i<m;i++){
            while(!ss.count(grid[i][start[i]]) || start[i] != ss.size() -1){
                ss.insert(grid[i][start[i]]);
                start[i]++;
                cond =false;
                
            }
        }
        if (cond){
            break;
        }
    }
    set<int> sss = set(ss.begin(),ss.end());
    cout << sss.size() <<endl;
    auto it =sss.begin();
    cout << *it;
    ++it;
    while (it != sss.end()){
        cout <<" ";
        cout << *it;
        ++it;
    }

}