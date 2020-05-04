#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

//BFS on graph
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
    
    void bfs(T src){
        queue<T> q;
        map<T,bool> visited;
        //start with the source
        q.push(src);
        visited[src] = true;
        
        //repeat until queue is empty
        while(!q.empty()){
            //pop the head
            T node = q.front();
            cout << node << " ";
            q.pop();
            //add its children
            for(T neighbor:adjList[node]){
                if(visited[neighbor] == false){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};


int main(){
    Graph<int> g;
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(4,2);
    g.addEdge(2,3);
    g.addEdge(2,0);
    
    g.printList();
    cout << "BFS" << endl;
    g.bfs(1);
}










