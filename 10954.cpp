#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    int T, a, b;
    vector <vector<int>> sum;
    vector <int> number;
    cin >> T;
    for (int i=0 ; i<T ; i++){
        cin >> a >> b;
        number = {a, b, a+b};
        sum.push_back(number);
    }

    for (int i=0; i<T ;i++){
        cout << "Case #" << (i+1) <<": "<< sum[i][0]<<" + "<< sum[i][1] <<" = "<< sum[i][2] << '\n';
    }
}