#include<iostream>
#include<map>
#include<list>
using namespace std;

//DFS FOR CYCLE DETECTION
//1. MAINTAIN BOOLS VISITED AND INSTACK FOR ALL VERTICES
//2. EVERY TIME NODE IS VISITED MAKE VISITED TRUE. ALSO INSTACK = TRUE
//3. EVERY TIME IT IS POPPED OUT EHILE RETURNING FROM DFS MAKE INSTACK FALSE
//4. IF BOTH ARE TRUE THEN CYCLE IS PRESENT

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
    
    bool dfsHelper(T node,map<T,bool> &visited,map<T,bool> &inStack){
        //mark the node
        visited[node] = true;
        inStack[node] = true;
        
        //visit children
        for(T neighbor:adjList[node]){
            if(!visited[neighbor] && dfsHelper(neighbor,visited,inStack) || inStack[neighbor]){
                return true;
            }
        }
        inStack[node] = false;
        return false;
    }
    
    bool dfs_cycle(){
        map<T,bool> visited;
        map<T,bool> inStack;
        
        //check for cycle in every tree of the forest
        for(auto i: adjList){
            T node = i.first;
            if(!visited[node]){
                bool cyclePresent = dfsHelper(node,visited,inStack);
                if(cyclePresent){
                    return true;
                }
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
    
    if(g.dfs_cycle()){
        cout << "Cycle is present" << endl;
    }
    else{
        cout << "Cycle not present" << endl;
    }
    
}











