#include <bits/stdc++.h>

using namespace std;
int main() {
    int t; cin >>t;
    string s;
    string f;
    bool c1 = true;
    cin >> s >>f;
    for (int i=0;i<s.length();i++){
        if (t%2 ==0){
            if (s[i] != f[i]){
                c1=false;
                break;
            }
        } else {
            if (s[i] == f[i]){
                c1=false;
                break;
            }
        }
    }
    if (c1){
        cout << "Deletion succeeded";
    } else {
        cout << "Deletion failed";
    }
}