#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    vector <int> find_max = {9,8,7,6,5,4,3,2,1,0};
    vector <int> find_min = {0,1,2,3,4,5,6,7,8,9};

    int K;
    cin >> K;
    vector <char> inequality;
    
    //부등호입력
    for (int i = 0; i<K; i++){
        char input;
        cin >> input;
        inequality.push_back(input);
    }

    while(1){
        int max_count = 0;
        for(int a = 0; a<K ; a++){
            if(inequality[a] == '<'){
                if(find_max[a] > find_max[a+1]) break;

            }else{
                if(find_max[a] < find_max[a+1]) break;
            }
            max_count ++;
        }
        
        if(max_count == inequality.size()){
            for(int i = 0; i<K+1; i++){
                cout<<find_max[i];
            }
            cout << '\n';
            break;
        }

        prev_permutation(find_max.begin(), find_max.end());
        
    }



    while(1){
        int min_count = 0;
        for(int a = 0; a<K ; a++){
            if(inequality[a] == '<'){
                if(find_min[a] > find_min[a+1]) break;

            }else{
                if(find_min[a] < find_min[a+1]) break;
            }
            min_count ++;
        }
        
        if(min_count == inequality.size()){
            for(int i = 0; i<K+1; i++){
                cout<<find_min[i];
            }
            break;
        }

        next_permutation(find_min.begin(), find_min.end());
        
    }
    
}