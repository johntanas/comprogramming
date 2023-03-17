#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , s, m,curr;
    cin >> n >> s>> m;
    int h =0;
    vector<int> board;
    board.push_back(0);
    for (int i=0;i<n;i++){
        cin >> curr;
        board.push_back(curr);
    }
    bool dat[n+1] ={false};
    while (true){
        if (s<=0){
            cout << "left" <<endl;
            cout << h;
            break;
        }
        if (s>n){
            cout << "right"<<endl;
            cout <<h;
            break;
        }
        if (dat[s]){
            cout << "cycle"<<endl;
            cout << h;
            break;
        }
        if (board.at(s) == m){
            cout << "magic" <<endl;
            cout << h;
            break;
        }
        dat[s] = true;
        if (board.at(s)<0){
            s += board.at(s);
        } else {
            s+= board.at(s);
        }
        h++;
    }
}