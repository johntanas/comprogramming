#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,curr =1;
    while (!cin.eof()){
        cin >>t;
        if (cin.eof()){
            break;
        }
        cout << "Case "<<curr <<":"<<endl;
        vector<int> v(t);
        for (int i=0;i<t;i++){
            cin >> v[i];
        }
        int m,a,e;
        cin >>e;
        vector<int> sum;
        for (int i=0;i<t;i++){
            for (int j=i+1;j<t;j++){
                if (i !=j){
                    sum.push_back(v.at(i)+v.at(j));
                }
            }
        }
        sort(sum.begin(),sum.end());
        for (int i=0;i<e;i++){
            int l=0,r=sum.size()-1;
            cin >> a;
            while (l<r){
                m= (l+r)/2;
                if (sum.at(m) == a){
                    break;
                } else if (sum.at(m) >a){
                    r=m;
                } else {
                    l=m+1;
                }
            }
            int out =m;
            if (m>0 && m<=sum.size()-1){
                if (abs(sum.at(m-1) -a) <abs(sum.at(m) -a)){
                    out = m-1;
                }
            }
            if (m>=0 && m<sum.size()-1){
                if (abs(sum.at(m+1) -a) <abs(sum.at(m) -a)){
                    if (abs(sum.at(m+1) -a) <abs(sum.at(out) -a)){
                        out = m+1;
                    }
                }
            }
            cout << "Closest sum to "<<a << " is "<<sum.at(out)<<".\n";
        }
        curr++;
    }
}
