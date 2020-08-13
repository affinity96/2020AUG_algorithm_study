# include <iostream>
# include <vector>

using namespace std;

int main(){
    int T, a, b;
    cin >> T;
    vector <int> arr;

    for (int i = 0; i<T; i++){
        cin >> a >>b ;
        arr.push_back(a+b);
    }
    for(int &i : arr){
        cout << i << '\n' ;
    }

}