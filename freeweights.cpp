#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,curr;
    cin >> t;
    vector<int> v(t);
    vector<int> v2(t);
    unordered_set<int> moved;
    for (int i=0;i<t;i++){
        cin  >> v[i];
    }
    for (int i=0;i<t;i++){
        cin  >> v2[i];
    }
    int m=0;
    for (int i=0;i<t;i++){
        if (m<v.at(i) && i!=t-1){
            moved.insert(m);
            m=v.at(i);
        } else if (m==v.at(i)){
            m=0;
        } else {
            moved.insert(v.at(i));
        }
    }
    moved.insert(m);
    for (int i=0;i<t;i++){
        if (m<v2.at(i) && i!=t-1){
            moved.insert(m);
            m=v2.at(i);
        } else if (m==v2.at(i)){
            m=0;
        } else {
            moved.insert(v2.at(i));
        }
    }
    moved.insert(m);
    m=0;
    for (auto it=moved.begin();it!= moved.end();it++){
        if (*it >m){
            m=*it;
        }
    }
    cout << m;
}
