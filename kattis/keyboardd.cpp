#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    int p =0,r=0;
    getline(cin,s);
    getline(cin,t);
    int c =0;
    unordered_set<char> set ;
    while (p<s.length() && r < t.length()){
        while (s.at(p)!=t.at(r)){
            c++;
            set.insert(t.at(r));
            r++;
        }
        p++;
        r++;
    }
    if (t.length()-s.length() != c){
        set.insert(t.at(t.length()-1));
    }
    for (char c:set){
        cout << c;
    }
    cout << endl;
}