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
    
    void dfs(T src){
        map<T,bool> visited;
        
        dfsHelper(src,visited);
        
    }
};


int main(){
    Graph<string> g;
    g.addEdge("Jake", "Charles");
    g.addEdge("Jake", "Terry");
    g.addEdge("Charles", "Gina");
    g.addEdge("Amy","Jake");
    g.addEdge("Rosa","Amy");
    g.addEdge("Amy","Gina");
    g.addEdge("Charles","Terry");
    g.addEdge("Terry","Rosa");
    
    g.dfs("Jake");
}










