#include <bits/stdc++.h>

using namespace std;

int main(){
    bool arr[999999] = {false};
    string f;
    string s;
    string ft,st;
    cin >> f >> s >> ft >> st;
    int idx =0;
    idx += (f.at(0)-'0')*600;
    idx += (f.at(1)-'0') *60;
    idx += (f.at(3)-'0') * 10;
    idx += (f.at(4)-'0');
    int per = 0;
    per+= (ft.at(0)-'0')*600;
    per += (ft.at(1)-'0')*60;
    per += (ft.at(3)-'0') * 10;
    per += (ft.at(4)-'0');
    while (idx<999999){
        arr[idx] =true;
        idx+= per;
    }
    idx =0,per =0;
    idx += (s.at(0)-'0')*600;
    idx += (s.at(1)-'0') *60;
    idx += (s.at(3)-'0') * 10;
    idx += (s.at(4)-'0');
    per+= (st.at(0)-'0')*600;
    per += (st.at(1)-'0')*60;
    per += (st.at(3)-'0') * 10;
    per += (st.at(4)-'0');
    while (idx<999999){
        if (arr[idx]){
            break;
        }
        idx+= per;
    }
    if (idx>=999999){
        cout << "Never";
    } else {
        idx %= 10080;
        if (idx <1440){
            cout <<"Saturday";
        } else if (idx <2*1440){
            cout<< "Sunday";
        } else if (idx <3 *1440){
            cout << "Monday";
        } else if (idx <4 *1440){
            cout << "Tuesday";
        } else if (idx < 5*1440){
            cout << "Wednesday";
        } else if (idx < 6*1440){
            cout << "Thursday";
        } else if (idx < 7*10080){
            cout << "Friday";
        }
        cout<< endl;
        idx %= 1440;
        cout << idx/600;
        idx %= 600;
        cout << idx/60;
        idx %=60;
        cout << ":"<< idx/10;
        idx%=10;
        cout << idx <<endl;
    }
}