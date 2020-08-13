#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    int T, n;
    cin >> T;
    int time_num[T];
    for (int i = 0; i<T; i++){
        cin >> n;
        time_num[i] = n;
    }
    sort(time_num, time_num+T);

    int res = 0;
    for (int i = 0; i<T; i++){
        res += (T-i)*time_num[i];
    }
    cout << res;
}