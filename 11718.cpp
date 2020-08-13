#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    vector <string> v;
    string s;

    while(1){
        getline(cin,s);
        if (cin.eof()){break;}
        v.push_back(s);
    }

    for(string ss : v){
        cout << ss<<'\n';
    }

}