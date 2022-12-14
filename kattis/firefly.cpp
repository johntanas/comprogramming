#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,h,a;
    cin >> n>>h;
    vector<int> v1(h,0);
    vector<int> v2(h,0);
    for (int i=0;i<n;i++){
        cin >>a;
        if (i &1){
            v1[h-a]++;
        } else {
            v2[a-1]++;
        }
    }
    int sum =0;
    for (int i=h-1;i>=0;i--){
        sum+= v2[i];
        v2[i] =sum;
    }
    sum =0;
    for (int i=0;i<h;i++){
        sum+= v1[i];
        v1[i] =sum;
    }
    int mm = 1<<30;
    int c =0;
    for (int i=0;i<h;i++){
        if (v1[i] +v2[i]<mm){
            mm = v1[i] +v2[i];
            c=0;
        }
        if (v1[i] +v2[i]==mm){
            c++;
        }
    }
    cout << mm<<" "<<c;
}