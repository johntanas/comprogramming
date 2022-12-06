#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    int g,m;
    long long c;
    for (int i =0; i<t;i++){
        long long gg =0;
        long long mm =0;
        cin >> g>> m;
        for (int j=0;j<g;j++){
            cin >> c;
            gg = max(c,gg);
        }
        for (int j=0;j<m;j++){
            cin >> c;
            mm = max(mm,c);
        }
        (mm>gg) ? printf("MechaGodzilla\n") : printf("Godzilla\n");
    }
}