#include <bits/stdc++.h>
using namespace std;
using pii =pair<long,long>;
int main(){
    int f,b,_;
    while (true){
        cin >> f;
        if (!f){
            break;
        }
        cin>>b;
        vector<double> v(f);
        vector<double> vv(b);
        for (int i=0;i<f;i++){
            cin >> v[i];
        }
        for(int i=0;i<b;i++){
            cin>>vv[i];
        }
        vector<double> ps;
        for (double i:v){
            for (double j:vv){
                ps.push_back((double) (i/j));
            }
        }   
        sort(ps.begin(),ps.end());
        vector<double> spread;
        int i=0;
        while (i+1<ps.size()){
            spread.push_back(ps.at(i+1)/ps.at(i));
            i+=1;
        }
        printf("%.2f\n",*max_element(spread.begin(),spread.end()));
    }
}
