#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >>m;
    int c = m%n;
    int cc = m/n;
    for (int i =1 ; i<=n;i++){
        if (i<=c){
            cout << '*';
        }
        for (int j=0;j<cc;j++){
            cout <<  '*';
        }
        cout << endl;
    }
}