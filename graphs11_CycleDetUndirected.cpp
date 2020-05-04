#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

//ALGORITHM:
//1. IF ANY NODE IS VISITED TWICE THEN THERE EXISTS A CYCLE!
//2. CAUTION: THE REVISITED NODE MUST NOT BE A PARENT

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
    
    
    bool bfs_cycle(T src){
        queue<T> q;
        map<T,bool> visited;
        map<T,string> parent;
        
        //initialize the parameters
        for(auto i:adjList){
            T node = i.first;
            visited[node] = false;
        }
        
        //initializing the source
        visited[src] = true;
        parent[src] = src;
        q.push(src);
        
        //repeat until queue is empty
        while(!q.empty()){
            //pop the head
            T node = q.front();
            q.pop();
            //add its children
            for(T neighbor:adjList[node]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = node;
                }
                else{
                    if(parent[node] != neighbor){
                        cout << "cycle exists!"<< endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }
};


int main(){
    
    Graph<string> g;
    g.addEdge("Eng", "PL");
    g.addEdge("Maths", "PL");
    g.addEdge("PL", "HTML");
    g.addEdge("Python","HTML");
    g.addEdge("JS","WebD");
    g.addEdge("WebD","HTML");
    g.addEdge("C++","Python");
    g.addEdge("HTML","Eng");
    cout << "Cycle Detection:";
    g.bfs_cycle("Eng");
}













