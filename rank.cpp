#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n>> m;
    vector<string> l;
    string c;
    for (int i =1;i<=n;i++){
        c= "T";
        c+= to_string(i);
        l.push_back(c);
    }
    string f,s;
    int fp,sp;
    for (int i =0;i<m;i++){
        cin >> f >> s;
        fp =distance(l.begin(),find(l.begin(),l.end(),f));
        sp =distance(l.begin(),find(l.begin(),l.end(),s));
        if (fp>sp){
            l.erase(l.begin()+sp);
            l.insert(l.begin()+fp,s);
        }
    }
    auto it = l.begin();
    cout << *it;
    ++it;
    while (it != l.end()){
        cout << " " << *it;
        ++it;
    }
}