#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))
using namespace std;
int main(){
    int t,curr =0;
    cin >> t;
    vector<int> v(t);
    for (int i =0;i<t;i++){
        cin >> v[i];
    }
    sort(v.rbegin(),v.rend());
    for (int i=0;i<t;i++){
        if (v[i]>=i+1){
            curr = i+1;
        } else {
            break;
        }
    }
    cout << curr;
}
