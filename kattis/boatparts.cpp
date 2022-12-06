#include <bits/stdc++.h>
using namespace std;
int main(){
    int p,n;
    cin >> p>>n;
    unordered_set<string> set ;
    string c;
    bool cond = true;
    for (int i =1;i<=n;i++){
        cin >>c;
        set.insert(c);
        if (set.size() == p){
            cout << i;
            cond = false;
            break;
        }
    }
    if (cond) {cout << "paradox avoided";}
}