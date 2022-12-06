#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n>> m;
    bool people[1001] ={false};
    int c;
    for (int i =0;i<n;i++){
        cin >> c;
        people[c] =true;
    }
    int trees[m] ={0};
    for (int i =0;i<m;i++){
        cin >> c;
        trees[i] =c;
    }
    sort(trees,trees+m);
    int p=0;
    bool occupied[m] = {false};
    int count =0;
    int idx =0;
    int tidx =0;
    while (idx <1001){
        if (people[idx]){
            while (tidx<m && idx>trees[tidx]){
                tidx++;
            }
            p= max(p,tidx-1);
            if (abs(trees[tidx]-idx) < abs(idx-trees[p])){
                if (occupied[tidx]) count++;
                occupied[tidx] = true;
            } else {
                if (occupied[p]) count++;
                occupied[p] = true;
            }
        }
        idx++;
    }
    cout << count;

}