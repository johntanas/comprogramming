#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,curr,k,r;
    cin >> k >> r;
    vector<int> v(k);
    for (int i=0;i<k;i++){
        cin >> v[i];
    }
    int out =0;
    for (int i=0;i<r;i++){
        int quan=1000000;
        for (int i=0;i<k;i++){
            cin >> curr;
            if (curr!=0){
                quan =min(quan,v[i]/curr);
            }
        }
        cin >> curr;
        out =max(curr*quan,out);
    }
    cout << out;
}
