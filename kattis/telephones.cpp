#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int main(){
    int t,curr,n,m;
    cin >> n>>m;
    while (n){
        vector<pii> v(n);
        for (int i =0;i<n;i++){
            cin >> t>> t>>t >> curr;
            v[i] =pii(t,t+curr); 
        }
        for (int i=0;i<m;i++){
            int c=0;
            cin >> t >> curr;
            int end = curr+t;
            for (pii p:v){
                if (p.first<=t){
                    if (t <p.second){
                        c++;
                    }
                } else if (p.first <end){
                    c++;
                }
            }
            cout <<c <<endl;
        }
        cin >> n>>m;
    }
}
