#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);

    int N;
    cin >> N;
    
    if(N==1){
        cout << "*";
        return 0;
    }
    int total_x = 4*N-1;
    int total_y = 4*N-3;
    string map[total_x][total_y];

    for (int i = 0; i<total_x ; i++){
        for (int j = 0; j<total_y ; j++){
            map[i][j] = " ";
       
        }
    }

   
    int dir_x = 1;
    int dir_y = -1;

    int x = 0;
    int y = total_y -1; //시작 지점 설정

    int count = 0; // 종료 플래그 설정
    int dir_flag = 0; // 현재 방향 설정 0:y의 증감(x축), 1: x의 증감(y축)

    while(count != total_y+1){

        if(dir_flag == 0){ //y가 증감할때 (x축으로 움직일 때 )
            // 앞 앞이 배열의 끝을 만날 경우
            if(((y + dir_y * 2) == 0 )||((y + dir_y * 2) == total_y-1) || (map[x][y+dir_y*2] == "*") ){
                if(map[x][y+ dir_y * 2] == " "){ //진짜 끝자락일 때
                    map[x][y] = "*";
                    map[x][y+ dir_y] ="*";
                    map[x][y+ dir_y * 2] ="*";
                    y = y+dir_y*2;
                    dir_y = dir_y * (-1) ; //이후 y의 증감을 변경하고
                    dir_flag = 1; //x의 증감으로 바꿔줘
                    count +=1;
                }else{
                    map[x][y] = "*";
                    dir_y = dir_y * (-1) ; //이후 y의 증감을 변경하고
                    dir_flag = 1; //x의 증감으로 바꿔줘
                    count +=1;
                }
        }else{
                map[x][y] = "*";
                y = y+ dir_y;
            }    
            
        }
        
        else{ //x가 증감 할 때 (y축으로 움직일 때)
            if(((x + dir_x * 2) == 0) || ((x + dir_x * 2) == total_x-1) || (map[x+dir_x*2][y] == "*")) {
                if(map[x+ dir_x * 2][y] == " "){ //진짜 끝자락일 때
                    map[x][y] = "*";
                    map[x+ dir_x * 1][y] ="*";
                    map[x+ dir_x * 2][y] ="*";
                    x = x+dir_x*2;
                    dir_x = dir_x * (-1);
                    dir_flag = 0; //y의 증감으로 바꿔줘
                    count +=1;
                }else{
                    map[x][y] = "*";
                    dir_x = dir_x * (-1);
                    dir_flag = 0; //y의 증감으로 바꿔줘
                    count +=1;
                }
            
            }else{
                map[x][y] = "*";
                x = x+ dir_x;
            
            } 
        }
    }
     for (int i = 0; i<total_x ; i++){
        for (int j = 0; j<total_y ; j++){
            if(i == 1 && j ==1){break;}
            cout << map[i][j];
        }
        cout << "\n";
    }

    return 0;
}