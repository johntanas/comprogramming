#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    char p ,c;
    p = '0';
    int score=0;
    for (int i =0;i<n;i++){
        cin >> c;
        if (p ==c){score++;}
        p=c;
    }
    cout << score;
}