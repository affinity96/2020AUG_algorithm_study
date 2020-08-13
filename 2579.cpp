#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie();
    cout.tie();

    int stair;
    cin >> stair;
    vector <int> answer(stair+1);
    vector <int> score_list = {0,};
    for(int i=0; i<stair; i++){
        int score;
        cin >> score;
        score_list.push_back(score);
    }

    if(stair == 0) {
        cout << 0;
        return 0;
    }else if(stair == 1){
        cout << score_list[1];
        return 0;
    }else if(stair == 2){
        cout << score_list[1] + score_list[2];
        return 0;
    }else{
        answer[0] = 0;
        answer[1] = score_list[1];
        answer[2] = max(score_list[1] + score_list[2], score_list[2]);
        answer[3] = max(score_list[1]+score_list[3], score_list[2]+score_list[3]);
        for(int i=4; i<stair+1; i++){
            // if(i == stair){
                answer[i] = max(answer[i-3]+score_list[i-1]+score_list[i], answer[i-2]+score_list[i]);
            // }else{
            //     answer[i] = max({answer[i-3]+score_list[i-1]+score_list[i], answer[i-2]+score_list[i], answer[i-1]});
            // }
        }

        cout << answer[stair];
    }
    
}