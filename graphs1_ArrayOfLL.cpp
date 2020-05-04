#include<iostream>
#include<list>
using namespace std;

//GRAPH WITH ARRAY OF LINKED LISTS

class Graph{
	int V;
	list<int> *l;

public:
	Graph(int v){
		V = v;
		//array of linked lists
		l = new list<int>[V];
	}

	void addEdge(int u, int v, bool bidir = true){
		l[u].push_back(v);
		if(bidir){
			l[v].push_back(u);
		}
	}

	void printAdjList(){

		cout<< "Your graph is:" << endl;
		for(int i = 0 ; i < V ; i++){
			cout << i <<": ";
			for(int vertex: l[i]){
				cout << vertex << " ";
			}
			cout << endl;
		}
	}


};

int main(){

	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(4,3);
	g.addEdge(3,1);
	g.addEdge(2,1);
	g.addEdge(2,4);

	g.printAdjList();

}
