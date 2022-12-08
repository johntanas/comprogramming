#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int main(){
    int c,n,t,m;
    cin >> c;
    while(c-->0){
        cin >> n>>t>>m;
        vector<queue<pii>> cars;
        cars.push_back({});
        cars.push_back({});
        int dat[m] ={0};
        int curr;
        string cmd;
        for (int i=0;i<m;i++){
            cin >> curr >> cmd;
            if (cmd=="left"){
                cars[0].push(pii(curr,i));
            } else {
                cars[1].push(pii(curr,i));
            }
        }
        int time =0;
        int index =0;
        while (!(cars[0].empty() && cars[1].empty())){
            int early = 1e9;
            if (!cars[0].empty()){
                early = cars[0].front().first;
            }
            if (!cars[1].empty()){
                early = min(early, cars[1].front().first);
            }
            time = max(time,early);
            int count =0;
            while (!cars[index].empty() && count<n && cars[index].front().first<=time){
                dat[cars[index].front().second]=time +t;
                count++;
                cars[index].pop();
            }
            index ^= 1;
            time +=t;
        }
        for (int i:dat){
            cout << i << endl;
        }
        cout<<endl;
    }
}