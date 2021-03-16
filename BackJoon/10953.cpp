#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    vector <int> res;
    string text;
    int T;
    cin >> T;
    for(int i = 0; i<T ; i++){
        cin >> text;
        istringstream iss(text);
        string token;
        int sum = 0;
        while(getline(iss,token,',')){
            sum += stoi(token);
        }
        res.push_back(sum);
    }
    for(int &num : res){
        cout << num << endl;
    }
    

}