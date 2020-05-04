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
    
    void dfsHelper(T node,map<T,bool> &visited,list<T> &ordering){
        //mark the node
        visited[node] = true;
        //visit children
        for(T neighbor:adjList[node]){
            if(!visited[neighbor]){
                dfsHelper(neighbor,visited,ordering);
            }
        }
        //after all children have been visited push it to the ordering list
        ordering.push_front(node);
    }
    
    void dfsTopologicalSort(){
        map<T,bool> visited;
        list<T> ordering;
        
        for(auto i:adjList){
            T node = i.first;
            if(!visited[node]){
                dfsHelper(node,visited,ordering);
            }
        }
        
        //print the order
        for(auto element:ordering){
            cout << element << " --> " ;
        }
        cout << endl;
    }
};


int main(){
    Graph<string> g;
    g.addEdge("Jake", "Charles",false);
    g.addEdge("Jake", "Terry",false);
    g.addEdge("Charles", "Gina",false);
    g.addEdge("Amy","Jake",false);
    g.addEdge("Rosa","Amy",false);
    g.addEdge("Amy","Gina",false);
    g.addEdge("Charles","Terry",false);
    g.addEdge("Terry","Rosa",false);
    
    g.dfsTopologicalSort();
}











