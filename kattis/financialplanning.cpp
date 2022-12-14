#include<bits/stdc++.h>
using namespace std;
using t = tuple<int,int,int>;
int main(){
    int n,m,a,b;
    cin >> n>>m;
    vector<t> v;
    for (int i=0;i<n;i++){
        cin  >> a >>b;
        v.push_back(t(a,b,b/a+1));
    }
    sort(v.begin(),v.end(),[](t a,t b){return (get<2>(a) == get<2>(b))? get<0>(a) == get<0>(b) ? get<1>(a)>get<1>(b) : get<0>(a)<get<0>(b) : get<2>(a)<get<2>(b);});
    int daily_p =0;
    int cost =0, days_need =-1,next =0, day = get<2>(v.at(0));
    while (true){
        while (next<v.size() && get<2>(v.at(next)) == day){
            int d = get<0>(v.at(next)), c = get<1>(v.at(next));
            cost += c;
            daily_p += d;
            next++;
        }
        if (day*daily_p -cost >=m){
            break;
        }
        day++;
    }
    cout << day <<endl;
}