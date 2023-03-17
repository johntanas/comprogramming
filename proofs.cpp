#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    unordered_set<string> set;
    string curr;
    bool conclusion = false;
    bool c=true;
    int i =1;
    while (i<=n){
        cin >> curr;
        if (conclusion){
            set.insert(curr);
            conclusion=false;
            i++;
        } else{
            if (curr == "->"){
                conclusion =true;
            }else if (!set.count(curr)){
                cout << i;
                c =false;
                break;
            }
        }
    }
    if (c){cout<<"correct";}
}