#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii = pair<int,int>;

bool check(pii a,pii b){
    if(a.x==b.x||a.y==b.y||(a.x+a.y)==(b.x+b.y)||(a.x-a.y)==(b.x-b.y)||(a.y-a.x)==(b.y-b.x)){
        return true;
    }
    return false;
}
int main(){
    int n,s,a;
    cin >> n;
    int idx=n;
    vector<pii> v;
    while (n-->0){
        cin >> s >> a;
        v.push_back(pii(s,a));
    }
    bool cond = true;
    for (int i=0;i<idx;i++){
        for (int j =i;j<idx;j++){
            if (i !=j && check(v[i],v[j])){cond =false;break;}
        }
    }
    if (cond){
        cout << "CORRECT";
    } else {
        cout << "INCORRECT";
    }
}