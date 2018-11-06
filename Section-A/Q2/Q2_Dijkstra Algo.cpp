/*
	From a given vertex in a weighted connected graph, find shortest paths to other
	vertices using Dijkstra's algorithm algorithm.
*/

/*
	Time Complexity: O(E.logV)
*/

using namespace std;
#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <stack>

typedef pair<int, int> Pair; 
 
struct Graph {

	int V;
	list< pair<int, int > > *adj;
};

Graph *create_Graph(int v) {
	Graph *G = new Graph;
	G->V = v;
	G->adj = new list<Pair>[G->V];
	return G;
}

void add_edge_undirected(Graph *G,int u,int v,int wght) {
	G->adj[u].push_back(make_pair(v, wght));
	G->adj[v].push_back(make_pair(u, wght));
}

void add_edge_directed(Graph *G,int u,int v,int wght) {
	G->adj[u].push_back(make_pair(v,wght));
}


void print_minCost_path(int *d, int *p, int V,int s) {

	cout <<"\n The minimum cost paths from the source vertex are : \n";
	cout<<"\n Source  Destination \t Minimum Cost \t Path\n";

	for ( int i=0; i<V; i++ ) {


		if ( d[i] != 0 ) {

			cout<<"  "<<s<<"\t"<<"    "<<i<<"\t\t"<<"    "<<d[i]<<"\t      ";

			int j = i;
			
			stack<int> path;
			while ( p[j] != -1 ) {
				path.push(j);
				j = p[j];	
			}

			path.push(j);

			cout << "   "<< path.top();
			path.pop();

			while (!path.empty()) {
				cout << "->" << path.top();
				path.pop();
			}
					
		}
		cout<<"\n";
	}
	cout<<"\n";

}


void Dijkstra(Graph *G, int s ) {

	// Initialising Single Source
	int *d = new int[G->V];
	int *p = new int[G->V];

	for ( int i = 0; i < G->V; i++ ){
		d[i] = 99999;
		p[i] = -1;
	}

	priority_queue< Pair,vector<Pair>,greater<Pair> > Q; 

	Q.push(make_pair(0,s));
	d[s] = 0;

	while ( !Q.empty() ) {

		int u = Q.top().second;
		Q.pop();

		list< pair<int, int> >:: iterator i;
		for ( i = G->adj[u].begin(); i != G->adj[u].end(); i++ ) {
			int v = (*i).first;
			int wght = (*i).second;

			// Relax a node
			if ( d[v] > d[u] + wght ) {
				d[v] = d[u] + wght;
				p[v] = u;
				Q.push(make_pair(d[v],v));
			}
		}
	}

	print_minCost_path(d,p,G->V,s);
}

int main() {

	int V, E;
	
	cout<<" Enter no of vertices : ";
	cin >>	V;

	cout<<" Enter no of Edges    : ";
	cin >> E;

	bool type;

	cout <<"\n Graph is Directed or Undirected ? "<<endl;
	cout <<" For Directed, Press 1."<<endl;
	cout <<" For Undirected, Press 0."<<endl;
	cout <<" Press Key for Desired Graph : ";
	cin >> type;

	cout<<"\n";

	Graph *G = create_Graph(V);

	int src, dest, wght;
	for (int i=0; i<E; i++) {

		cout << " Enter Source Vertex      : ";
		cin >> src;
		
		cout << " Enter Destination Vertex : ";
		cin >> dest;

		cout << " Enter Weight             : ";
		cin >> wght;

		if ( type == 0 ) 
			add_edge_undirected(G, src, dest, wght);
		else if ( type == 1 )
			add_edge_directed(G, src, dest, wght);

		cout<<"\n";
	}

	
	int s;

	cout << "\n Enter the source node        : ";
	cin >> s;

	Dijkstra(G,s);

	return 0;
}









