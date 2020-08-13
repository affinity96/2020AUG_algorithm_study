#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class XY{
    public: 
        int x;
        int y;
        XY(int x, int y){
            this->x = x;
            this->y = y;
        }
};

bool compare(XY one, XY two){
    if(one.y == two.y){
        return one.x < two.x;
    }else{
        return one.y < two.y;
    }
        
}

int main (){
    ios_base :: sync_with_stdio(0);

    int N, x, y;
    cin >> N;
    vector <XY> numbers;
    for(int i = 0 ; i<N ; i++){
        cin >> x >> y;
        numbers.push_back(XY(x, y));
    }

    sort(numbers.begin(), numbers.end(), compare);

    for(int i = 0 ; i<N ; i++){
        cout << numbers[i].x <<' '<< numbers[i].y << '\n';
     
    }

}