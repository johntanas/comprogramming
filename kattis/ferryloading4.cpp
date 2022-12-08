#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vpii = vector<queue<pii>>;
int main(){
    int c;
    cin >> c;
    int l,m;
    while(c-->0){
        cin >> l >> m;
        l*=100;
        int ll;
        string cmd;
        vpii cars= {{},{}};
        for (int i =0;i<m;i++){
            cin >> ll >> cmd;
            if (cmd=="left"){
                cars[0].push(pii(ll,i));
            } else {
                cars[1].push(pii(ll,i));
            }
        }
        int index =0;
        int times =0;
        while (!(cars[0].empty() && cars[1].empty())){
            int count =0;
            while (!cars[index].empty() && count<=l){
                count+=cars[index].front().first;
                if (count>l){
                    break;
                }
                cars[index].pop();
            }
            index ^= 1;
            times ++;
        }
        cout << times << endl;
    }
}