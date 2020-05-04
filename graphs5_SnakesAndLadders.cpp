#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

//Snakes and Ladders BFS
/*
 THE IDEA IS TO CONSTRUCT A GRAPH FROM EACH POINTON THE BOARD
 ADD A NEW EDGE FOR EVERY THROW OF THE DIE FROM 1 TO 6
 ADD EDGES ALAG SE FOR THE LADDERS AND SNAKES
 TRAVERSE BACK FROM DEST TO SOURCE VIA PARENT TO RETRACE THE PATH
 
 */
template <typename T>
class Graph{
    map<T,list<T> > adjList;
public:
    Graph(){
        //useless constructor
    }
    
    void addEdge(T u, T v, bool bidir = true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    
    void printList(){
        //iterate over the map
        for(auto i:adjList){
            cout << i.first << ": ";
            for(auto edges:i.second){
                cout << edges << " ";
            }
            cout << endl;
        }
    }
    
    int bfs(T src, T dest){
        queue<T> q;
        map<T,int> dist;
        map<T,T> parent;
        
        //set all distances to int_max
        for(auto i:adjList){
            dist[i.first] = INT_MAX;
        }
        
        //start with the source
        q.push(src);
        dist[src] = 0;
        parent[src] = src;
        
        //repeat until queue is empty
        while(!q.empty()){
            //pop the head
            T node = q.front();
            q.pop();
            //add its children
            for(T neighbor:adjList[node]){
                if(dist[neighbor] == INT_MAX){
                    q.push(neighbor);
                    parent[neighbor] = node;
                    dist[neighbor] = dist[node] + 1;
                }
            }
        }
        cout << endl;
        //print distances to all nodes
//        for(auto i: adjList){
//            T node = i.first;
//            //cout << "Distance of "<< node << " is " << dist[node] << endl;
//        }
        
        //printing the path
        T temp = dest;
        while(temp != src){
            cout << temp << " <--" ;
            temp = parent[temp];
        }
        cout << src << endl;
        
        return dist[dest];
    }
};


int main(){
    Graph<int> g;
    
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;
    
    //constructing the graph
    for(int u = 0 ; u <= 36 ; u++){
        for(int dice = 1 ; dice <= 6 ; dice++){
            int v = u + dice + board[u + dice];
            g.addEdge(u,v,false);
        }
    }
    
    cout << "Distance between source and destination is " << g.bfs(0,36) << endl;
}











