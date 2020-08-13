#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    
    int n;

    cin >> n;
    vector <int> answer(10001);
    vector <int> grape(10001);
    for (int i=1; i<n+1; i++){
        int each_grape;
        cin >> each_grape;
        grape[i] = each_grape;

    }

    if(n == 1) {
        cout << grape[1];
        return 0;
    } 
    else if(n == 2) {
        cout << grape[1]+grape[2];
        return 0;
    } 
    else{
        answer[1] = grape[1];
        answer[2] = grape[1] + grape[2];

        for(int i=3; i<=grape.size()-1; i++){

            answer[i] = max(answer[i-1], max(answer[i-2]+grape[i], answer[i-3]+grape[i-1]+grape[i]));

        }

        cout << answer[n];
    }


    
}