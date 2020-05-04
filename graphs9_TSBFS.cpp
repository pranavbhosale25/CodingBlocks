#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

//BFS on graph - Kahn's Algorithm - Topological Sort
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
    
    
    void bfs(){
        queue<T> q;
        map<T,bool> visited;
        map<T,int> indegree;
        
        //initialize the parameters
        for(auto i:adjList){
            T node = i.first;
            visited[node] = false;
            indegree[node] = 0;
        }
        
        //initialize all indegrees
        for(auto i:adjList){
            T u = i.first;
            for(T v:adjList[u]){
                indegree[v]++;
            }
        }
        
        //find all nodes with 0 indegree
        for(auto i:adjList){
            T node = i.first;
            if(indegree[node] == 0){
                q.push(node);
            }
        }
        
        //repeat until queue is empty
        while(!q.empty()){
            //pop the head
            T node = q.front();
            q.pop();
            cout << node << " --> ";
            //add its children
            for(T neighbor:adjList[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
    }
};


int main(){
//    Graph<int> g;
//    g.addEdge(1,0,false);
//    g.addEdge(1,2,false);
//    g.addEdge(1,4,false);
//    g.addEdge(4,2,false);
//    g.addEdge(2,3,false);
//    g.addEdge(2,0,false);

    
    Graph<string> g;
    g.addEdge("Eng", "PL",false);
    g.addEdge("Maths", "PL",false);
    g.addEdge("PL", "HTML",false);
    g.addEdge("Python","HTML",false);
    g.addEdge("JS","WebD",false);
    g.addEdge("WebD","HTML",false);
    g.addEdge("C++","Python",false);
    cout << "Topological Sort:" << endl;
    g.bfs();
}











