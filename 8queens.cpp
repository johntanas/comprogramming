#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii = pair<int,int>;
bool check(pii a, pii b){
    if (a.x ==b.x || a.y == b.y || a.x+a.y == b.y +b.x || a.y-a.x == b.y -a.x || a.x -a.y == b.x-b.y){
        return true;
    }
    return false;
}
int main(){
    vector<pii> v;
    char t;
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            cin >>t;
            if (t=='*'){v.push_back(pii(i,j));}
        }
    }
    bool cond = true;
    if (v.size()==8){
        for (int i=0;i<8;i++){
            for (int j=1;j<8;j++){
                if (i!=j && check(v.at(i),v.at(j))){
                    cond = false; break;
                }
            }
        }
    }
    if (cond && v.size() ==8){
        cout << "valid";
    } else {
        cout << "invalid";
    }
}