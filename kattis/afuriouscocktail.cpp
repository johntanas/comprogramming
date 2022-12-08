#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin >> n >> t;
    int arr[n] ={0};
    for (int i =0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n,greater());
    bool cond = true;
    for ( int j=0;j<n+1;j++){
        for (int i =0;i<j-1;i++){
            arr[i]-=t;
            if (arr[i]<=0){
                cond = false;
            }
        }
    }
    if (cond){
        cout << "YES";
    } else {
        cout << "NO";
    }
}