#include <bits/stdc++.h>

using namespace std;
using  vpii =vector<pair<long,long>>;
int main(){
    int n,k;
    cin >> n >> k;
    vpii a;
    vpii b;
    vpii c;
    long aa, bb ,cc;
    for (int i =0;i<n;i++){
        cin >> aa >> bb >> cc;
        a.push_back(pair(aa,i));
        b.push_back(pair(bb,i));
        c.push_back(pair(cc,i));
    }
    sort(a.begin(),a.end(),greater());
    sort(b.begin(),b.end(),greater());
    sort(c.begin(),c.end(),greater());
    bool taken[n] = {false};
    int ccc =0;
    for (int i =0;i<k;i++){
        if (!taken[a.at(i).second]){
            ccc++;
            taken[a.at(i).second] = true;
        }
        if (!taken[b.at(i).second]){
            ccc++;
            taken[b.at(i).second] = true;
        }
        if (!taken[c.at(i).second]){
            ccc++;
            taken[c.at(i).second] = true;
        }
    }
    cout << ccc;
}