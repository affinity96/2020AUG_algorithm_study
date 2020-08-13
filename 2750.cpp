#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    vector <int> vec;
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        int num ; 
        cin >>num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());
    for (int a=0; a<vec.size(); a++){
        cout << vec[a] << '\n';
    }
}