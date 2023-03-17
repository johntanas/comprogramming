#include <bits/stdc++.h>
using namespace std;
int main(){
    string cmd;
    map<string,int> enter;
    map<string,int> cost;
    string person;
    int time;
    int day =1;
    while (cin >> cmd){
        if (cmd == "OPEN"){
            enter.clear();
            cost.clear();
        }
        if (cmd =="ENTER"){
            cin >> person;
            cin >> enter[person];
        }
        if (cmd =="EXIT"){
            cin >> person >> time;
            cost[person] += time - enter[person];
        }
        if (cmd =="CLOSE"){
            cout << "Day "<< day << endl;
            day++;
            for (auto it = cost.begin();it != cost.end();it++){
                cout << it->first << " $";
                printf("%0.2f\n",(double) it->second/10);
            }
        }
    }
}