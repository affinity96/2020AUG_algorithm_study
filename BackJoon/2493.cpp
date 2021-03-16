#include <iostream>
#include <stack>


using namespace std;
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL); //????
   
    int N, H;

    cin >> N;
    stack<pair<int,int>> toop;
    for(int i = 0 ; i < N; i++)
	{

		cin >> H;
        
		while (!toop.empty() && toop.top().second < H){
            toop.pop();
            
        }
			
        if (toop.empty()) {
            cout << "0 ";
        }
        else{
            cout << toop.top().first <<' ';
        }
                    
                
			
        
		toop.push(make_pair(i+1, H)); 	
        }
}