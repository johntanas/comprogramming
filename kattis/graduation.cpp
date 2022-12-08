#include <bits/stdc++.h>
using namespace std;
class Union {
    public:
    int p[26],rank[26];
    Union(int n){
        for (int i =0;i<n;i++){
            p[i] = i;
            rank[i] =1;
        }
    }
    int findSet(int i){
        if (p[i] ==i){
            return i;
        }
        p[i] = findSet(p[i]);
        return p[i];
    }
    void unionSet(int i,int j){
        if (findSet(i) == findSet(j)){
            return;
        }
        int l,r;
        l=findSet(i); r= findSet(j);
        if (rank[l]>rank[r]){
            p[r] =l;
        } else {
            if (rank[l] == rank[r]){
                p[r] =l;
                rank[l]++;
            } else {
                p[l] =r;
            }
        }
    }
};
int main(){
    int n,m,k;
    cin >> n >> m>>k;
    char grid[n][m];
    Union u =Union(k);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    for (int j=0;j<m;j++){
        char curr = grid[0][j];
        for(int i=1;i<n;i++){
            u.unionSet(curr-'A',grid[i][j]-'A');
        }
    }
    unordered_set<char> set;
    for (int i =0;i<k;i++){
        set.insert(u.findSet(u.p[i]));
    }
    cout << set.size() << endl;
}