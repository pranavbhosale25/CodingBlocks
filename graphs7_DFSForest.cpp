#include<iostream>
#include<map>
#include<list>
using namespace std;

//DFS ON GRAPH
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
    
    void dfsHelper(T node,map<T,bool> &visited){
        //mark the node
        visited[node] = true;
        cout << node << "   ";
        //visit children
        for(T neighbor:adjList[node]){
            if(!visited[neighbor]){
                dfsHelper(neighbor,visited);
            }
        }
    }
    
    void dfs_forest(T src){
        map<T,bool> visited;
        int forests = 0;
        dfsHelper(src,visited);
        cout << endl;
        
        for(auto i:adjList){
            T city = i.first;
            if(!visited[city]){
                dfsHelper(city,visited);
                cout << endl;
                forests++;
            }
        }
        
        
    }
};


int main(){
    Graph<string> g;
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Delhi", "Jaipur");
    g.addEdge("Mumbai","Jaipur");
    g.addEdge("Mumbai","Bhopal");
    g.addEdge("Delhi","Bhopal");
    g.addEdge("Mumbai","Bangalore");
    g.addEdge("Agra","Delhi");
    g.addEdge("Andaman","Nicobar");
    
    g.dfs_forest("Amritsar");
}











