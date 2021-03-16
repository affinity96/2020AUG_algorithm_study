#include <iostream>
#include <vector>

using namespace std;

int main(){

    int M,N;
    cin >> M >> N;
    ios_base :: sync_with_stdio(0);

    vector <bool> check(1000001);
    check.flip();

    check[1] = false;

    for(int i=2; (i*i)<1000001; i++){
        if(check[i]){
            for(int j = 2*i; j<1000001; j+=i){
                check[j] = false;
            }
        }
    }

    for(int i = M; i<N+1; i++){
        if(check[i]) {
            cout<<i<<'\n';
            }
    }
}