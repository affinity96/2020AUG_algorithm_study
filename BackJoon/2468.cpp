#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie();

    int N;
    int max_safety_zone =0;
    int max =0, min = 101;

    cin >> N;
    vector <vector<int>> map(N);
    vector <vector<bool>> visited(N);
    queue <pair<int, int>> bfs_queue;

    for (int i = 0; i<N; i++){
        vector<bool> visited_elem(N);
        visited[i] = visited_elem;
        for(int j = 0; j<N; j++){
            int map_elem;
            cin >> map_elem;
            if(map_elem > max) max = map_elem;
            if(map_elem < min) min = map_elem;
            map[i].push_back(map_elem);
        }
    }
    if(max == min) {
        cout << 1;
        return 0;
    }
    vector <vector<int>> copied_map(N);
    copied_map.assign(map.begin(), map.end());

    for(int rain=min; rain<max+1; rain++){
        for (int i = 0; i<N; i++){
            vector<bool> visited_elem(N);
            visited[i] = visited_elem;
        }
        int safety_zone = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){

                    if(map[i][j] > rain && visited[i][j] == false){
                        bfs_queue.push(make_pair(i,j));
                        visited[i][j] = true;
                        while(!bfs_queue.empty()){
                            int cur_i = bfs_queue.front().first;
                            int cur_j = bfs_queue.front().second;
                            bfs_queue.pop();
                            for(int counter =0; counter<4; counter++){
                                int new_i = cur_i + dx[counter];
                                int new_j = cur_j + dy[counter];
                                if (new_i == -1 || new_j == -1 || new_i == N || new_j == N)  continue;
                                if(map[new_i][new_j] > rain && visited[new_i][new_j]==false){
                                    bfs_queue.push(make_pair(new_i, new_j));
                                    visited[new_i][new_j] = true;           
                                }
                            
                            }   
                         }
                         safety_zone +=1;          
                     }else continue;
                }

         }
    if(max_safety_zone < safety_zone) max_safety_zone = safety_zone;

    }

    cout << max_safety_zone;
}