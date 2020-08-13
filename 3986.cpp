#include <iostream>
#include <stack>


using namespace std;

int main(){
    
 ios_base :: sync_with_stdio(0);


 int N;
 int count = 0;
 cin >> N;
 string doc;
 for (int i = 0 ; i<N; i++){
    
    stack <char> text;
    cin >> doc;

     for(int n = 0; n < doc.size(); n++){
         if(text.empty()){
             text.push(doc[n]);
         }else{
             if(text.top() == doc[n]){
             text.pop();
            }else{
                text.push(doc[n]);
            }
         }

         
     }
     if(text.empty()){
         count++;
     }
 }   
 cout << count;
}