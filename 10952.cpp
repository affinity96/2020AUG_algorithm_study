# include <iostream>
# include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    vector <int> arr;
    int a,b;
    while(1){
        cin >> a >>b ;
        if(a==0 && b==0) {
            break;
        }
        arr.push_back(a+b);
    }
    for (int &num : arr){
        cout << num << '\n';
    }
    

}