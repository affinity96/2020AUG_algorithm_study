#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);

    int N;
    long long key_num;
    map <long long, int> numbers;
    cin >> N;

    for (int i = 0; i<N ; i++){
        cin >> key_num;
        if(numbers.find(key_num) == numbers.end()){
            numbers.insert(make_pair(key_num, 1));
        }else{
            numbers.at(key_num) =  numbers.at(key_num) +1;
        }
    }

    long long max_num = 0 ;
    int max_count = 0;
    for (auto it = numbers.begin(); it!=numbers.end() ; it ++){
        if (it->second > max_count){
            max_num = it->first;
            max_count = it->second;
        }
    }

    cout << max_num;

   

}