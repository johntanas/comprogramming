#include <bits/stdc++.h>
// TLE
using namespace std;
using pii = pair<int,int>;
class t {
    public:
    int f,s,tt;
    t(int ff,int ss, int ttt){
        f=ff; s=ss; tt =ttt;
    }
};
int main(){
    int w,h;
    cin >> w >> h;
    int grid[h][w];
    char curr;
    int sr,sc;
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cin >>curr;
            if (curr =='S'){
                sr=i,sc=j;
                grid[i][j] =-1;
            } else if (curr =='#'){
                grid[i][j] = -2;
            } else {
                grid[i][j] =-1;
            }
        }
    }
    string directions;
    cin >> directions;
    int dr[] ={1,0,-1,0};
    int dc[] ={0,1,0,-1};
    queue<t> q;
    q.push(t(sr,sc,0));
    while (!q.empty()){
        t min =q.front();
        q.pop();
        if (grid[min.f][min.s] != -1 || min.tt> directions.length()) {continue;}
        grid[min.f][min.s] = min.tt;
        for (int d=0;d<4;d++){
            int r = min.f +dr[d];
            int c = min.s +dc[d];
            if (r<0 || c< 0 || r>= h || c>=w) {continue;}
            q.push(t(r,c,min.tt+1));
        }
    }
    q.push(t(sr,sc,0));
    while (!q.empty()){
        t min =q.front();
        q.pop();
        if (min.tt != grid[min.f][min.s]){continue;}
        if (min.tt == directions.length()){
            if (grid[min.f][min.s] == min.tt){
                grid[min.f][min.s] = -3;
            }
            continue;
        }
        grid[min.f][min.s] =-1;
        int c;
        if (directions.at(min.tt) == 'S'){
            c=0;
        } else if (directions.at(min.tt) == 'N'){
            c=2;
        } else if (directions.at(min.tt) == 'E'){
            c=1;
        } else {
            c=3;
        }
        for (int d=0;d<4;d++){
            if (d==c){continue;}
            int r = min.f +dr[d];
            int c = min.s +dc[d];
            if (r<0 || c< 0 || r>= h || c>=w) {continue;}
            q.push(t(r,c,min.tt+1));
        }
    }
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            if (grid[i][j] ==-2){
                cout << '#';
            } else if (grid[i][j] ==-3){
                cout << '!';
            } else if (i ==sr && j==sc) {
                cout << 'S';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
}