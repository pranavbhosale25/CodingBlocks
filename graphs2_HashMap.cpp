#include<iostream>
#include<map>
#include<list>
using namespace std;

//Generic graph using hash maps
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
};


int main(){
	Graph<string> g;
	g.addEdge("Jake", "Charles");
	g.addEdge("Amy","Jake");
	g.addEdge("Rosa","Amy");
	g.addEdge("Jake","Gina");
	g.addEdge("Charles","Terry");
	g.addEdge("Terry","Rosa");

	g.printList();
}









