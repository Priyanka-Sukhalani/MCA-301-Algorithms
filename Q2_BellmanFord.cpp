/*
	From a given vertex in a weighted connected graph, find shortest paths to other
	vertices using bellman’s ford algorithm.
*/

/*
	Time Complexity: O(VE)
					 For Complete Graphs, T(n) = O (V^3).
*/


using namespace std;
#include <iostream>
#include <stack>

struct Edge 
{
	int src, dest;
	int wght;
};
struct Graph
{
	int V,E;
	Edge *edge;
};

Graph *create_Graph ( int v, int e) {
	Graph *G = new Graph;
	G->V = v;
	G->E = e;
	G->edge = new Edge[e];
	return G;
}

void Relax(Graph *G,int *d,int *p) {
	for ( int i = 0 ; i < (G->V)-1 ; i++ ) {
		for ( int j = 0 ; j < (G->E) ; j++) {
			
			int u 	 = G->edge[j].src;
			int v 	 = G->edge[j].dest;
			int wght = G->edge[j].wght;

			// Relax an edge with minimum weight

			if ( d[v] > d[u] + wght ) {
				d[v] = d[u] + wght;
				p[v] = u;
			}
		}
	}
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

void Bellman_Ford(Graph *G, int s){

	// Initialising Single Source
	int *d = new int[G->V];
	int *p = new int[G->V];
	int flag = 0;

	for ( int i = 0; i < G->V; i++ ){
		d[i] = 99999;
		p[i] = -1;
	}

	d[s] = 0;

	Relax(G,d,p);	
	// Actual BellMan Ford Algorithm Working

	for ( int i = 0; i < G->E; i++ ) {
		int u    = G->edge[i].src;
		int v    = G->edge[i].dest;
		int wght = G->edge[i].wght;

		//checking negative edge cycle
		if ( d[v] > d[u] + wght ) {
				flag = 1;
				break;
		} 
	}

	if ( flag == 1 )
		cout << "\n Graph contains negative edge cycles. \n";
	else {

		print_minCost_path(d,p,G->V,s);
	}
}

int main() {

	int V, E;
	
	cout<<" Enter no of vertices : ";
	cin >>	V;
	cout<<" Enter no of edges    : ";
	cin >> E;
	
	cout<<"\n";

	Graph *G = create_Graph(V,E);

	for (int i=0; i<E; i++) {
		cout << " Enter Source Vertex      : ";
		cin >> G->edge[i].src;
		
		cout << " Enter Destination Vertex : ";
		cin >> G->edge[i].dest;

		cout << " Enter Weight             : ";
		cin >> G->edge[i].wght;

		cout<<"\n";
	}

	int s;

	cout << "\n Enter the source node        : ";
	cin >> s;

	Bellman_Ford(G, s);
}