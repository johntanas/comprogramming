#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int c=0;
    for (int i=0;i<s.size();i++){
        unordered_set<char> set;
        char f = s.at(i);
        for (int j=i+1;j<s.size();j++){
            if (f == s.at(j)) {break;}
            if (set.count(s.at(j))){continue;}
            set.insert(s.at(j));
            c+=1;
        }
    }
    cout << c;
}
