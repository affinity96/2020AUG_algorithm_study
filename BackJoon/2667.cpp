#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie();
    stack <pair<int, int>> dfs_stack;
    
    vector <int> house_num;
    vector <int> total_group;
    int group_count = 0;
    vector <vector<int>> detection = {{0,1}, {1,0}, {0,-1},{-1,0}};
    int N;
    string each_numbers;
    cin >> N;
    vector <string> map;
    bool isvisited [N][N];

    for (int i=0; i<N; i++){
        cin >> each_numbers;
        map.push_back(each_numbers);

    }


    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            group_count = 0;
            if (map[i][j] == '0') continue;
            else{
                isvisited[i][j] = true;
                group_count++;
                dfs_stack.push(make_pair(i,j));
                
                while(!dfs_stack.empty()){
                    
                    pair<int, int> current=dfs_stack.top();
                
                    dfs_stack.pop();
                    for(int a = 0; a<4; a++){
                        int new_i = current.first+detection[a][0];
                        int new_j = current.second+detection[a][1];
                        if(new_i == -1 || new_j == -1 || new_i == N || new_j == N)  continue;
                        if(map[new_i][new_j] == '1' && isvisited[new_i][new_j] == false){
                            isvisited[new_i][new_j] = true;
                            dfs_stack.push(make_pair(current.first, current.second));
                           
                            dfs_stack.push(make_pair(new_i, new_j));
                            group_count ++;
                            break;
                        }
                    }
                    
                }
                if(group_count !=1) total_group.push_back(group_count);
            }
        }
         
    }
    
    cout << total_group.size() << '\n';
    sort(total_group.begin(), total_group.end());
    for(int i: total_group){
        cout << i << '\n';
    }
}