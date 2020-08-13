#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main(){    
    ios_base :: sync_with_stdio(0);
    cin.tie();
    cout.tie();
    queue<int> bfs_queue;
    
    int n, start, end, relation;
    cin >> n;
    cin >> start >> end;
    cin >> relation;

    vector <vector<int>> rel_graph (n+1);
    vector<int> visited(n+1);

    for (int i=0; i<relation; i++){
        int rel1, rel2;

        cin >> rel1 >> rel2;
        rel_graph[rel1].push_back(rel2);
        rel_graph[rel2].push_back(rel1);
    
    }
    bfs_queue.push(start);
    visited[start] = 1;
    while(!bfs_queue.empty()){
        int current_idx = bfs_queue.front();

        bfs_queue.pop();
        for(int i=0; i<rel_graph[current_idx].size(); i++){
            int next_idx = rel_graph[current_idx][i];
            if(visited[next_idx] == 0){
                bfs_queue.push(rel_graph[current_idx][i]);
                visited[next_idx] = visited[current_idx]+1;
                
            }

        }
    }
    cout<<visited[end]-1;
  

}