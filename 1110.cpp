#include <iostream>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);

    int N, com = 0;
    cin >> N;
    int mok, na = 0;
    int count = 0;
    com = N;
    while(1){
        count +=1;
        mok = com/10;
        na = com%10;
        int next_one = (mok + na)%10;
        int new_num = na*10 + next_one;
        if(new_num == N){break;}
        else {com = new_num;}
    }
    cout << count;
    
}