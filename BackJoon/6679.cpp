#include <iostream>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);

    for(int num = 2992; num<10000; num++){
        int cur_num = num;
        int sum_10=0,sum_16=0,sum_12=0, mok, na;
        for(int i=0; i<4; i++){
            mok = cur_num / 10;
            na = cur_num % 10;
            sum_10 +=na;
            cur_num = mok;
        }

        cur_num = num;
        for(int i=0; i<4; i++){
            mok = cur_num / 16;
            na = cur_num % 16;
            sum_16 +=na;
            cur_num = mok;
        }

        cur_num = num;

        for(int i=0; i<4; i++){
            mok = cur_num / 12;
            na = cur_num % 12;
            sum_12 +=na;
            cur_num = mok;
        }



        if((sum_10 == sum_12) && (sum_12 == sum_16)){
            cout << num << '\n';
        }
    }
}