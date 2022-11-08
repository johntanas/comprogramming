#include <iostream>
#include <vector>
using namespace std;
int main(){
    int c;
    cin >> c;
    int temp;
    int prev =0;
    vector<int> s = {};
    while (c--){
        cin >> temp;
        if (temp>prev)
            s.push_back(temp);
            prev =temp;
    }
    cout << s.size() << "\n";
    cout << s.at(0);
    int i=1;
    while (i<s.size()){
        cout << " " << s.at(i);
        ++i;
    }
    cout << "\n";

}