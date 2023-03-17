#include <bits/stdc++.h>
using namespace std;
class Union {
    public:
    int p[200000], rank[200000],size[200000];
    Union(int n){
        for (int i =0;i<n;i++){
            p[i] = i;
            rank[i] =1;
            size[i] = 1;
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
            size[l] += size[r];
        } else {
            if (rank[l] == rank[r]){
                p[r] =l;
                rank[l]++;
                size[l] += size[r];
            } else {
                p[l] =r;
                size[r] += size[l];
            }
        }
    }
};
int main(){
    int n;
    cin >> n;
    Union u =Union(200000);
    unordered_map<string,int> map;
    int pos =0;
    string f;
    string s;
    for (int i=0;i<n;i++){
        cin >> f >> s;
        if (map.find(f) == map.end()){
            map[f]=pos++;
        }
        if (map.find(s)== map.end()){
            map[s] =pos++;
        }
        u.unionSet(map[f],map[s]);
        cout << u.size[u.findSet(map[f])] <<endl;
    }
}