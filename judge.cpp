#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    unordered_map<string,int> dom;
    unordered_map<string,int> kat;
    cin >>n;
    string s;
    for (int i=0;i<n;i++){
        cin >>s;
        dom[s] ++;
    }
    for (int i=0;i<n;i++){
        cin >>s;
        kat[s]++;
    }
    int sum =0;
    for (const auto& [k,v] : dom){
        sum += min(kat[k],v);
    }
    cout <<sum;
}