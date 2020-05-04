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
    
    bool isCyclicHelper(T node,map<T,bool> &visited, T parent){
        //mark the node
        visited[node] = true;
        
        //visit children
        for(T neighbor:adjList[node]){
            //parent[neighbor] = node;
//            if(visited[neighbor] && neighbor != node || isCyclicHelper(neighbor,visited,parent)){
//                return true;
//            }
            
            if(!visited[node]){
                bool cycleDet = isCyclicHelper(neighbor,visited,node);
                if(cycleDet){
                    return true;
                }
            }
            //neighbor already visited
            else if(neighbor != parent){
                return true;
            }
        }
        return false;
    }
    
    bool isCyclic(){
        map<T,bool> visited;
        
        for(auto i:adjList){
            T node = i.first;
            if(!visited[node]){
                bool cycle = isCyclicHelper(node,visited,node);
                if(cycle)
                    return true;
            }
        }
        return false;
    }
};


int main(){
    Graph<int> g;
    g.addEdge(0,1,false);
    g.addEdge(0,2,false);
    g.addEdge(1,5,false);
    g.addEdge(2,4,false);
    g.addEdge(4,5,false);
    g.addEdge(2,3,false);
    g.addEdge(3,0,false);
    
    if(g.isCyclic()){
        cout << "Cycle is present" << endl;
    }
    else{
        cout << "Cycle not present" << endl;
    }

}











