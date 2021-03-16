#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);

    int N, mok, na;
    vector <int> numbers;
    cin >> N;
    int temp = N;
    while(1){
        na = temp % 10;
        mok = temp / 10;
        numbers.push_back(na);
        if(mok == 0) break;
        temp = mok;
    }
  
    sort(numbers.begin(), numbers.end(), greater<int>());
    for(int &n : numbers) cout<<n;

}