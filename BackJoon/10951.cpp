# include <iostream>
# include <vector>


using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    string text;
    cin >> text;
    vector <int> arr;
    int a,b;
    while(1){
        cin >> a >>b ;
        if(cin.eof()) {
            break;
        }
        arr.push_back(a+b);
    }
    for (int &num : arr){
        cout << num << '\n';
    }
    

}