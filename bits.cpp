#include <bits/stdc++.h>
using namespace std;
int main(){
    long t,c;
    cin >> t;
    while(t-->0){
        cin >> c;
        int m =0;
        while (c){
            m = max(__builtin_popcount(c),m);
            c /=10;
        }
        cout << m <<endl;
    }
}