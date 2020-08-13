#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
    ios_base :: sync_with_stdio(0);
    int N, normal_count=0, saek_count=0;
    cin >> N;
    vector<string> grid(N);
    vector<string> saek_grid(N);
    vector<vector<bool>> visited(N);
    vector<vector<bool>> saek_visited(N);
    queue <pair<int,int>> bfs_queue;
    for (int i=0; i<N; i++){
        vector<bool> visited_elem(N);
        vector<bool> saek_visited_elem(N);
        visited[i] = visited_elem;
        saek_visited[i] = saek_visited_elem;
        string grid_element;
        cin >> grid_element;
        grid[i] = grid_element;
        for(int j=0; j<N; j++){
            if(grid_element[j] == 'G'){
                grid_element[j] = 'R';
            }
        }
        saek_grid[i] = grid_element;
        
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if(visited[i][j] == false){
                bfs_queue.push(make_pair(i,j));
                visited[i][j] = true;
                while(!bfs_queue.empty()){
                    int cur_i = bfs_queue.front().first;
                    int cur_j = bfs_queue.front().second;
                    bfs_queue.pop();
                    for(int cnt=0; cnt<4; cnt++){
                        int new_i = cur_i+dx[cnt];
                        int new_j = cur_j+dy[cnt];
                        if (new_i == -1 || new_j == -1 || new_i == N || new_j == N)  continue;
                        if (grid[new_i][new_j] == grid[cur_i][cur_j] && visited[new_i][new_j] == false){
                            bfs_queue.push(make_pair(new_i, new_j));
                            visited[new_i][new_j] = true;
                        }

                    }
                }
                normal_count ++;
            }
        }
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if(saek_visited[i][j] == false){
                bfs_queue.push(make_pair(i,j));
                saek_visited[i][j] = true;
                while(!bfs_queue.empty()){
                    int cur_i = bfs_queue.front().first;
                    int cur_j = bfs_queue.front().second;
                    bfs_queue.pop();
                    for(int cnt=0; cnt<4; cnt++){
                        int new_i = cur_i+dx[cnt];
                        int new_j = cur_j+dy[cnt];
                        if (new_i == -1 || new_j == -1 || new_i == N || new_j == N)  continue;
                        if (saek_grid[new_i][new_j] == saek_grid[cur_i][cur_j] && saek_visited[new_i][new_j] == false){
                            bfs_queue.push(make_pair(new_i, new_j));
                            saek_visited[new_i][new_j] = true;
                        }

                    }
                }
                saek_count ++;
            }
        }
    }

    cout << normal_count <<' '<< saek_count;
}