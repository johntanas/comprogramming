#include <bits/stdc++.h>
using namespace std;
int main(){
    long n,k,c,curr;
    cin >> n >> k;
    bool cond = false;
    for (int i =1;i<=n;i++){
        cin >> curr;
        if (cond && i%k ==0){
            cout << " ";
        }
        if (i%k ==0){
            cout << curr;
            cond =true;
        }

    }
}