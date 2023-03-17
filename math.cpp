#include <bits/stdc++.h>
using namespace std;
using t = tuple<int,int,int>;
int main(){
    int b,d,c,l;
    cin >> b >>d >>c >>l;
    vector<t> v;
    int o1,o2,o3;
    for (int i =0;i<l/b+b;i++){
        int o1 = i*b;
        for (int j=0;j<l/d+d;j++){
            o2 =o1 +d *j;
            for(int k=0;k<l/c+c;k++){
                o3 =o2 +c*k;
                if (o3 ==l){
                    v.push_back(t(i,j,k));
                }
            }
        }
    }
    if (v.size()){
        for (t tt:v){
                cout << get<0>(tt) << " " << get<1>(tt) << " "<< get<2>(tt)<<"\n";
        }
    } else {
        cout << "impossible";
    }

}
