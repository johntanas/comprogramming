#include <bits/stdc++.h>
using namespace std;
int main(){
   vector<int> v(9);
   int e =0;
   for (int i=0;i<9;i++){
        cin >> v[i];
   }
   e =accumulate(v.begin(),v.end(),e);
   int r,c;
   for (int i=0;i<9;i++){
        int s = e-v.at(i);
        for (int j=i;j<9;j++){
            if (i !=j){
                if (s-v.at(j) ==100){
                    r=i,c=j;
                }
            }
        }
   }
   for (int i=0;i<9;i++){
        if (i ==r || i ==c){
            continue;
        }
        cout << v.at(i) <<"\n";
   }
}
