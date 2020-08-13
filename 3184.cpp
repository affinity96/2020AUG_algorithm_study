#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie();
    int survived_sheep = 0;
    int survived_wolf = 0;
    queue <pair<int,int>> bfs_queue;
    int R,C;
    cin >> R >> C;
    vector<string>map(R);
    vector<vector<bool>>visited(R);      

    for (int i = 0; i<R; i++){
        vector<bool> visited_elem(C);
        visited[i] = visited_elem;
    }
    for(int r=0; r<R; r++){
        string map_elem;
        cin >> map_elem;
        map[r] = map_elem;

    }



    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            int sheep=0 , wolf = 0;
            if(map[i][j] == '#' || visited[i][j] == true) continue;
            else{
                bfs_queue.push(make_pair(i,j));
                visited[i][j] = true;
                if(map[i][j] == 'o'){
                    sheep ++;
                }
                if(map[i][j]=='v'){
                    wolf ++;
                }

                while(!bfs_queue.empty()){
                    int cur_i = bfs_queue.front().first;
                    int cur_j = bfs_queue.front().second;
                    bfs_queue.pop();
                    for(int cnt=0; cnt<4; cnt++){
                        int new_i = cur_i+dx[cnt];
                        int new_j = cur_j+dy[cnt];
                        if (new_i == -1 || new_j == -1 || new_i == R || new_j == C)  continue;
                        if (map[new_i][new_j] != '#' && visited[new_i][new_j] == false){
                            bfs_queue.push(make_pair(new_i, new_j));
                            visited[new_i][new_j] = true;
                            if(map[new_i][new_j] == 'o'){
                                sheep ++;
                            }else if(map[new_i][new_j]=='v'){
                                wolf ++;
                            }
                        }
                    }
                }
                if(sheep > wolf){
                    survived_sheep += sheep;
                }else{
                    survived_wolf += wolf;
                }

            }

            

        }
    }

    cout << survived_sheep <<' '<< survived_wolf;

}