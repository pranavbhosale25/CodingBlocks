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
            cout << node << " ";
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
        for(auto i: dist){
            cout << "Distance of " << i.first << " from " << src << " is " << i.second << endl;
        }
    }
};


int main(){
    Graph<int> g;
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(4,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(3,4);
    g.printList();
    cout << endl;
    cout << "BFS" << endl;
    g.bfs(0);
}











