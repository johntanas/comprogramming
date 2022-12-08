#include<bits/stdc++.h>
using namespace std;
void solve(int t){
    vector<int> v(t);
    vector<int> pos(t);
    for (int i=0;i<t;i++){
        cin >> v[i];
        pos[v[i]] =i;
    }
    for (int i=0;i<t;i++){
        for (int d=-t;d<=t;d++){
            if (i+2*d>=0 && i+2*d<t){
                if (pos[i]<pos[i+d] && pos[i+d] < pos[i+2*d]){
                    cout << "no" << endl;
                    return;
                }
            }
        }
    }
    cout  <<"yes" << endl;
    return;
}
int main(){
    int t,g;
    char _;
    cin>>t;
    while (t){
        cin >> _;
        solve(t);
        cin >> t;
    }
}
