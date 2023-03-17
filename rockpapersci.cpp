#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int k;
    while (n !=0){
        cin >> k;
        long win[n+1] ={0};
        long loss[n+1]={0};
        int p1,p2;
        string ps,rs;
        for (int i =0;i<(k*n*(n-1)/2);i++){
            cin >> p1 >> ps >> p2 >> rs;
            if (ps.compare(rs)==0)continue;
            if (ps.compare("paper") ==0 ){
                if (rs.compare("rock") ==0){
                win[p1]++;loss[p2]++;
                } else {win[p2]++;loss[p1]++;}
            }
            if (ps.compare("scissors") ==0) {
                if (rs.compare("paper") ==0){
                    win[p1]++;loss[p2]++;
                }
                else {win[p2]++;loss[p1]++;}
            }
            if (ps.compare("rock") == 0 ) {
                if (rs.compare("scissors")==0){
                    win[p1]++;loss[p2]++;
                }else {
                    win[p2]++;loss[p1]++;
                }
            }
        }
        for (int i =1;i<=n;i++){
            if (loss[i] ==0 && win[i]==0){
                cout<< "-" <<endl;
            } else {
                float rr =  (float) win[i]/(win[i]+loss[i]);
                printf("%.3f\n",rr);
            }
        }
        cout<<endl;
        cin>> n;
    }
}