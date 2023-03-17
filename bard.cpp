#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,e;
    cin >> n>>e;
    vector<set<int>> v(n+1);
    int k;
    int idx=0;
    for (int i =0;i<e;i++){
        cin >> k;
        vector<int> ppl;
        bool bard =false;
        int c;
        for (int j=0;j<k;j++){
            cin >> c;
            if (c==1) {bard=true;}
            ppl.push_back(c);
        }
        set<int> ss;
        if (bard){
            for (int j:ppl){
                v.at(j).insert(idx);
            }
            idx++;
        } else {
            for (int j: ppl){
                for (int curr : v.at(j)){
                    ss.insert(curr);
                }
            }
            for (int j:ppl){
                v[j] = ss;
            }
        }
    }
    for (int i =1 ;i<=n;i++){
        if (v[i].size() == idx){
            cout << i <<endl;
        }
    }
}