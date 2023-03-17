#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    int x;
    int curr =0;
    map<int,int> map;
    int xx;
    string cmd;
    for (int i=0;i<q;i++){
        cin >> cmd >>x;
        if (cmd=="RESTART"){curr =x; map.clear();}
        if (cmd == "PRINT"){
            if (map.find(x) !=map.end()){
                cout << map.find(x)->second;
            } else {
                cout << curr;
            }
            cout << endl;
        }
        if (cmd =="SET"){
            cin >> xx;
            map[x] =xx;
        }
    }
}