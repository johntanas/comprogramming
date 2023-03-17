#include <bits/stdc++.h>
using namespace std;
int main(){
    int s,n,m;
    cin>> s>>n>>m;
    vector<int> v;
    int t;
    for (int i=0;i<s;i++){
        cin >> t;
        v.push_back(t);
    }
    int peaks =0,valleys=0;
    int prev = v.at(0);
    int length =0;
    bool possible =false;
    bool increasing =true;
    vector<int> rise ={1};
    for (int i=1;i<s;i++){
        int curr = v.at(i);
        if (curr > prev){
            if (rise.at(rise.size()-1)>=0){
                rise.at(rise.size()-1)++;
            } else {
                rise.push_back(2);
            }
        } else{
            if (rise.at(rise.size()-1)>=0){
                rise.push_back(-2);
            } else {
                rise.at(rise.size()-1)--;
            }
        }
        prev = curr;
    }
    prev = rise.at(0);
    for (int i =1;i<rise.size();i++){
        int curr = rise.at(i);
        if (prev<0){
            if (abs(prev)>=m && curr >=m){
                valleys++;
            }
        } else {
            if (abs(curr)>=n && prev >=n){
                peaks++;
            }
        }
        prev = curr;
    }
    cout << peaks << " "<<valleys;
}