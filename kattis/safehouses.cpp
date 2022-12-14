#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int main(){
    int r;
    char c;
    cin >> r;
    vector<pii> spy;
    vector<pii> house;
    for (int i=0;i<r;i++){
        for (int j=0;j<r;j++){
            cin >> c;
            if (c=='H'){
                house.push_back(pii(i,j));
            }
            if (c=='S'){
                spy.push_back(pii(i,j));
            }
        }
    }
    int m=0;
    for (pii s:spy){
        int curr=r*r;
        for (pii h:house){
            curr=min(abs(h.first-s.first)+abs(h.second-s.second),curr);
        }
        m=max(m,curr);
    }
    cout << m;
}
