#include<bits/stdc++.h>
using namespace std;
int main(){
    string line;
    unordered_map<string,string> map;
    while (getline(cin,line) && line != ""){
        string english, foreign;
        int index = line.find(' ');
        english = line.substr(0, index);
        foreign = line.substr(index+1, line.size()-1);

        map.insert({foreign, english});
    }
    while (getline(cin,line)){
        if (map.count(line)>0){
            cout << map.find(line)->second;
        } else {
            cout << "eh";
        }
        cout << endl;
    }
}