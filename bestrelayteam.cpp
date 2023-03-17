#include<bits/stdc++.h>
using namespace std;
using Tii = tuple<string,double,double>;
int main(){
    int t;
    double u,v;
    cin >>t;
    string s;
    vector<Tii> n;
    for (int i=0;i<t;i++){
        cin >> s>> u >>v;
        n.push_back(Tii(s,u,v));
    }
    double min =99999;
    vector<Tii> best;
    sort(n.begin(),n.end(),[](Tii c1,Tii c2){return get<2>(c1)<get<2>(c2);});
    for (int i =0;i<t;i++){
        double time =get<1>(n.at(i));
        vector<Tii> stuff;
        stuff.push_back(n.at(i));
        for (int j=0;j<t;j++){
            if (i ==j){
                continue;
            }
            stuff.push_back(n.at(j));
            time += get<2>(n.at(j));
            if (stuff.size() ==4){
                break;
            }
        }
        if (min> time){
            best = stuff;
            min =time;
        }
    }
    printf("%.2f\n",min);
    for (Tii t: best){
        s= (string) get<0>(t);
        cout << s <<endl;
    }
}
