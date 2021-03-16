#include <iostream>
#include <vector>


using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    vector <string> w_first = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
    };
    vector <string> b_first = {
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB"
    };
    
    int N, M;
    int min_value = 100000;
    cin >> N >> M;
    vector <string> rows;
    string row;
    for(int i=0; i<N; i++){
        cin >> row;
        rows.push_back(row);
    }
    for(int x=0 ; x<N-7 ; x++){
        for (int y = 0; y< M-7 ; y++){
            int count_w = 0;
            int count_b = 0;
            for (int x_dir = 0; x_dir <8; x_dir++){
                for(int y_dir = 0; y_dir<8; y_dir++){
                    if(rows[x+x_dir][y+y_dir] != w_first[x_dir][y_dir]){
                        count_w++;
                    }else{
                        count_b++;
                    }
                }
            }  
        if(min(count_w, count_b) < min_value){
            min_value = min(count_w, count_b);
        }

        }
    }

    cout << min_value;
}