#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    int N, M, num;
    string cardstring;
    vector <int> card;
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        cin >> num;
        if(num < M){
            card.push_back(num);
        }
    }
    
    // while(next_permutation(card.begin(), card.end())){
    //     int sum = 0;
    //     for(int a=0; a<3; a++){
    //         sum+=card[a];
    //     }

    //     if (sum > max && sum <= M){
    //         max = sum;
    //     }
    // }
    
    int sum, max = 0;
    for(int a = 0; a<N; a++){
        for(int b=0 ; b<N; b++){
            if(a==b){break;}
            for (int c=0; c<N; c++){
                if(a==c || b==c){break;}
                else{
                    sum = card[a]+ card[b]+ card[c];
                    if(sum >= max && sum <= M){
                        max = sum;
                    }
                }
            }
        }
    }
    cout << max;
}