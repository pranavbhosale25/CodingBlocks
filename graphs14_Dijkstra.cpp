#include<iostream>
#include<map>
#include<list>
#include<set>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

//DIJKSTRA'S ALGORITHM
//1. WORKS FOR WEIGHTED GRAPHS
//2. FINDS SHORTEST PATH FROM SRC NODE TO ALL NODES

template <typename T>

class Graph{
    map <T, list<pair<T, int> > > m;
public:
    Graph(){
        //useless constructor
    }
    
    void addEdge(T u, T v, int dist,bool bidir = true){
        m[u].push_back(make_pair(v,dist));
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }
        
    }
    
    
    void printAdj(){
        //iterate over the map
        
        for(auto i:m){
            cout << i.first << ": ";
            for(auto edges:i.second){
                cout << "("<< edges.first << "," << edges.second << ")"<<" ";
            }
            cout << endl;
        }
    }
    
    void dijkstra(T src){
        //create a map for distance to each node
        map <T,int> dist;
        
        //initialize all distances to infinity
        for(auto j:m){
            dist[j.first] = INT_MAX;
        }
        
        //make set to find node with minimum distance
        set <pair<int,T> > s;
        
        //set distance for source as zero
        dist[src] = 0;
        
        //initialize the set/priority queue
        s.insert(make_pair(0,src));
        
        //add all neighbors
        while(!s.empty()){
            //find the node at the beginning and collect its info
            auto p = *(s.begin());
            
            T node = p.second;
            int nodeDist = p.first;
            
            //pop this node
            s.erase(s.begin());
            
            //iterate over neighbors of the current node
            for(auto childPair:m[node]){
                if(nodeDist + childPair.second < dist[childPair.first]){
                    //now update in the set
                    //cannot update in set so remove and insert again
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    
                    //if not found then the iterator f reaches the end of the set
                    if(f != s.end()){
                        s.erase(f);
                    }
                    
                    //now insert new pair
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        //print distances from source to each node
        for(auto d:dist){
            cout << d.first << " is located at a dist of " << d.second << endl;
        }
    }
    
    
    
};


int main(){
    Graph<int> g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,5,2);
    g.addEdge(2,4,7);
    g.addEdge(4,5,6);
    g.addEdge(2,3,1);
    g.addEdge(0,5,2);
    
    g.dijkstra(0);
    
    
    
}












