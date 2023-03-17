#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y,n;
    double shield;
    cin >> x>>y >> n;
    for (int i=0;i<n;i++){
        double s,e,m;
        cin >> s>>e>>m;
        shield+= m*(e-s);
        y-=e-s;
    }
    cout << fixed <<setprecision(7) << x/(shield+y) <<endl;
}