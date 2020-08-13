#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);

    int N, num;
    cin >> N;
    vector <int> res (10001);

    for(int i=0; i<N ; i++){
        cin >> num;
        res[num] ++;
    }

    for(int a=0; a<res.size(); a++){
        if(res[a]!=0){
            for(int b=0; b<res[a]; b++){
                cout<<a<<'\n';
            }
        }
    }
}