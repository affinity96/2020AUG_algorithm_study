#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie();
    
    int N,M,knowing_true_num;
    
    cin >> N >> M;
    cin >> knowing_true_num;
    vector<vector<int>>party(M);
    vector<bool> is_he_know(N+1); 
    vector<bool> she_is_liar(M+1);
    

    for (int i=1; i<knowing_true_num+1; i++){
        int he_know;
        cin >> he_know;
        is_he_know[he_know] = true;
    }



    for (int i=0; i<M; i++){
        int party_people;
        int party_person;
        vector<int> each_party;
        cin >> party_people;

        for(int j=0; j<party_people; j++){
            int person_num;
            cin >> person_num;
            each_party.push_back(person_num);
        }
        party[i] = each_party;
    }
//요까지 입력

    
    for(int a=0; a<M; a++){
        for(int i=0; i<M; i++){
            for (int j=0; j<party[i].size(); j++){

                if(is_he_know[party[i][j]] == true){
                    for (int k=0; k<party[i].size(); k++){
                        is_he_know[party[i][k]] = true;
                    }
                    she_is_liar[i] = true;
                }

            }
        }
    }
    int count = 0;
    for(int i=0; i<she_is_liar.size(); i++){
        if(!she_is_liar[i]){
            count ++;
        }
    }

cout << count-1;
}