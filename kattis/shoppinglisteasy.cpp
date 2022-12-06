#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >>m;
    vector<string> p;
    vector<string> c;
    string curr;
    for (int i=0;i<n;i++){
        vector<string> c;
        for (int j =0;j<m;j++){
            cin >> curr;
            c.push_back(curr);
        }
        if (i ==0){
            p=c;
            sort(p.begin(),p.end());
        } else {
            sort(c.begin(),c.end());
            auto itt = set_intersection(p.begin(),p.end(),c.begin(),c.end(),c.begin());
            c.resize(itt-c.begin());
            p=c;
        }
    }   
    cout << p.size() << endl;
    for (auto it =p.begin();it != p.end();++it){
        cout << *it <<endl;
    }
}