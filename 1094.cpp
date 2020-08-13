#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    vector<int> numbers = {64, 32, 16, 8, 4, 2, 1};
    int X;
    cin>>X;
    int count=0;
    for (int i=0; i<numbers.size(); i++){
        if(X >= numbers[i]){
            X = X-numbers[i];
            count++;
            if(X==0) break;
        }
        
    }

    cout << count;

}