#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main (){
    ios_base :: sync_with_stdio(0);
    int N,M ; 
    cin >> N >> M;
    vector <string> didnt_hear_list;
    vector <string> didnt_see_list;
    vector <string> answer;
    string didnt_hear;
    string didnt_see;
    for(int i=0; i<N; i++){
        cin >> didnt_hear;
        didnt_hear_list.push_back(didnt_hear);
    }

    sort(didnt_hear_list.begin(), didnt_hear_list.end());
    for (int i=0; i<M; i++){
        cin >> didnt_see;
        if(binary_search(didnt_hear_list.begin(), didnt_hear_list.end(), didnt_see)){
            answer.push_back(didnt_see);
        }else{
            continue;
            
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for(string ans : answer){
        cout << ans <<'\n';
    }



}