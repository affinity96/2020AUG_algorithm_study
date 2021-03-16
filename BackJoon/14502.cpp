#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie();
    queue <pair<int,int>> bfs_queue;
    int N, M;
    int max_count = 0;
    cin >> N >> M;
    vector<vector<int>> lab(N);
    vector<vector<int>> copied_lab(N);
    vector<pair<int,int>> index;
    for (int i =0; i<N; i++){
        for (int j=0; j<M; j++){
            int elem;
            cin >> elem;
            if(elem == 0){
                index.push_back(make_pair(i, j));
            }
            lab[i].push_back(elem);    
        }
   }
    // for(int i=0; i<index.size(); i++){

    //             cout << index[i].first << index[i].second;
  
    //         cout << "\n";
    //     }
    //     cout << "\n";
   int length_idx = index.size();

   for(int first_wall=0; first_wall<length_idx; first_wall++){
       for(int second_wall=0; second_wall<length_idx; second_wall++){
           if(first_wall==second_wall) continue;
           for(int third_wall = 0; third_wall<length_idx; third_wall++){
            if(second_wall==third_wall || first_wall == third_wall) continue;
               
               copied_lab.assign( lab.begin(), lab.end() );

               copied_lab[index[first_wall].first][index[first_wall].second] = 1;
               copied_lab[index[second_wall].first][index[second_wall].second] = 1;
               copied_lab[index[third_wall].first][index[third_wall].second] = 1;
                // for(int i=0; i<N; i++){
                //     for (int j=0; j<M; j++){
                //         cout << copied_lab[i][j];
                //     }
                //     cout << "\n";
                // }
                // cout << "\n";
                vector<vector<bool>>visited(N);      
                for (int i = 0; i<N; i++){
                    vector<bool> visited_elem(M);
                    visited[i] = visited_elem;
                }

               for(int i=0; i<N; i++){
                   for(int j=0; j<M; j++){
                       if(copied_lab[i][j] !=2 || visited[i][j] == true) continue;
                       else{
                           bfs_queue.push(make_pair(i,j));
                           visited[i][j] = true;
                           while(!bfs_queue.empty()){
                                int cur_i = bfs_queue.front().first;
                                int cur_j = bfs_queue.front().second;
                                bfs_queue.pop();
                                for(int cnt=0; cnt<4; cnt++){
                                    int new_i = cur_i+dx[cnt];
                                    int new_j = cur_j+dy[cnt];
                                    if (new_i == -1 || new_j == -1 || new_i == N || new_j == M)  continue;
                                    if (copied_lab[new_i][new_j] == 0 && visited[new_i][new_j] == false){
                                        bfs_queue.push(make_pair(new_i, new_j));
                                        visited[new_i][new_j] = true;
                                    }
                                }
                           }
                       }
                   }
               }
            int count = 0;
            for(int a = 0; a<N; a++){
                for (int b=0; b<M; b++){
                    if(visited[a][b] == false && copied_lab[a][b]==0){
                        count++;
                    }
                }
            }

            if(count > max_count) max_count = count;



               
           }
       }
   }
   cout << max_count;

}