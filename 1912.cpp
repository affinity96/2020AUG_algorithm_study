#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie();
    cout.tie();

    int n, num;
    vector <int> numbers;
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        numbers.push_back(num);
    }

    vector <int> answer(n);
    answer[0] = numbers[0];
    
    for(int i = 1; i<n; i++){
        answer[i] = max({answer[i-1]+numbers[i], numbers[i]});
    }

    sort(answer.begin(), answer.end());
    cout << answer[n-1];


}